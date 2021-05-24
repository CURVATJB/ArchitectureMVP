#include "BackGroundWorker.h"

#include <iostream>

BackgroundWorker::BackgroundWorker()
	: m_isRunning(false)
{
	m_pThread = std::make_unique<std::thread>([this]()
		{
			m_isRunning = true;
			Start();
		});
}

BackgroundWorker::~BackgroundWorker()
{
	if (m_isRunning)
	{
		Stop();
	}
}

void BackgroundWorker::Wait()
{
	std::unique_lock<std::mutex> lock(m_mutex);
	while (!m_jobs.empty())
	{
		m_synchronizer.wait(lock);
	}
}

void BackgroundWorker::Stop()
{
	{
		std::lock_guard<std::mutex> l(m_mutex);
		m_isRunning = false;
		m_synchronizer.notify_one();
	}
	m_pThread->join();
}

void BackgroundWorker::Sync(const Job& job)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_jobs.push_back(job);
	m_synchronizer.notify_one();
}

void BackgroundWorker::Async(const Job& job)
{
	std::condition_variable event;
	auto finished = false;

	std::unique_lock < std::mutex> lock(m_mutex);
	const auto lambda = [this, &job, &finished, &event]()
	{
		job();
		std::lock_guard<std::mutex> l(m_mutex);
		finished = true;
		event.notify_one();
	};

	m_jobs.emplace_back(lambda);
	m_synchronizer.notify_one();

	while (!finished)
		event.wait(lock);
}

void BackgroundWorker::Start()
{
	std::unique_lock<std::mutex> lock(m_mutex);

	while (m_isRunning)
	{
		while (m_isRunning && m_jobs.empty())
		{
			m_synchronizer.wait(lock);
		}
		while (!m_jobs.empty())
		{
			const auto size = m_jobs.size();
			std::cout << "Pending jobs: " << size << std::endl;
			const auto firstJob = m_jobs.front();
			m_jobs.pop_front();
			lock.unlock();
			firstJob();
			lock.lock();
		}

		m_synchronizer.notify_all();
	}

	m_synchronizer.notify_all();
}
