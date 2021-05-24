#pragma once
#include "IModel.h"
#include <thread>

class ConcreteModel : public IModel
{
public:
	explicit ConcreteModel(BackgroundWorker* pBackgroundWorker)
		: IModel(pBackgroundWorker)
	{

	}

	void Compute()
	{
		const std::function<void()> f = []()
		{
			std::cout << "Compute ont this thread: " << std::this_thread::get_id() << std::endl;
		};

		AsyncPost<>(f);
	}
};
