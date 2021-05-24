#ifndef IVIEW_H
#define IVIEW_H
#include <iostream>

class IView
{
public:
	
	explicit IView()
	{
		std::cout << "IView: " << std::this_thread::get_id() << std::endl;
	}

	virtual ~IView() = default;
};

#endif //IVIEW_H
