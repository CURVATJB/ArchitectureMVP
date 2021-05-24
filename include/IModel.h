#ifndef IMODEL_H
#define IMODEL_H

#include <iostream>

#include "BackGroundWorker.h"

class IModel
{
public:

	explicit IModel(BackgroundWorker* pBackgroundWorker)
		: m_pBackgroundWorker(pBackgroundWorker)
	{
		std::cout << "Model: " << std::this_thread::get_id() << std::endl;
	}

	virtual ~IModel() = default;

	void Print() const
	{
		m_pBackgroundWorker->Async([]()
			{
				std::cout << "Model: " << std::this_thread::get_id() << std::endl;
			});
	}

	template<typename... Args>
	void AsyncPost(std::function<void(Args...)> f)
	{
		m_pBackgroundWorker->Async(f);
	}

protected:

	BackgroundWorker* m_pBackgroundWorker;
};

#endif //IMODEL_H
