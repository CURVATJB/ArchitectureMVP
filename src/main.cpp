#include "ConcretePresenter.h"
#include <iostream>

int main()
{
	const auto pPresenter = std::make_unique<ConcretePresenter>();
	auto pModel = dynamic_cast<ConcreteModel*>(pPresenter->GetModel());
	auto pView = dynamic_cast<ConcreteView*>(pPresenter->GetView());
	
	while (true)
	{
		std::cout << "ui: " << std::this_thread::get_id() << std::endl;
		pModel->Compute();
		pView->Display();
	}

	return  0;
}
