#pragma once
#include "IView.h"
#include <thread>

class ConcreteView : public IView
{
public:
	ConcreteView() = default;
	~ConcreteView() = default;

	void Display()
	{
		std::cout << "View displayed on this thread: " << std::this_thread::get_id() << std::endl;
	}
};