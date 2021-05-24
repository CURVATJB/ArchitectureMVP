#pragma once
#include "BackGroundWorker.h"

template<class Model, class View>
class Threading
{
public:
	Threading()
		: m_pBackgroundWorker(std::make_unique<BackgroundWorker>())
	{
		m_pBackgroundWorker->Sync([this]()
			{
				Model(m_pBackgroundWorker.get());
			});
		View();
	}

protected:
	std::unique_ptr<BackgroundWorker> m_pBackgroundWorker;
};