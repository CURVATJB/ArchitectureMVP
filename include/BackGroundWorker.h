#ifndef BACKGROUNDWORKER_H
#define BACKGROUNDWORKER_H

#include <functional>
#include <list>
#include <mutex>

using Job = std::function<void()>;
using Jobs = std::list<Job>;

class BackgroundWorker
{
public:
	BackgroundWorker();
	~BackgroundWorker();

	void Wait();
	void Stop();
	void Sync(const Job& job);
	void Async(const Job& job);

private:
	void Start();

	std::condition_variable m_synchronizer;
	std::mutex m_mutex;
	std::unique_ptr<std::thread> m_pThread;
	Jobs m_jobs;
	volatile bool m_isRunning;
};

#endif //BACKGROUNDWORKER_H
