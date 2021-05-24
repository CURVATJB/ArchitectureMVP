#ifndef IPRESENTER_H
#define IPRESENTER_H

#include "Threading.h"
#include "IView.h"
#include "IModel.h"
#include <memory>

template<typename Model, typename View>
class IPresenter : public Threading<IModel, IView>
{
public:
	IPresenter()
		:m_pModel(std::make_shared<Model>(m_pBackgroundWorker.get()))
		, m_pView(std::make_shared<View>())
	{

	}

	virtual ~IPresenter() = default;

	IModel* GetModel() const
	{
		return m_pModel.get();
	}

	IView* GetView() const
	{
		return m_pView.get();
	}

protected:
	std::shared_ptr<IModel> m_pModel;
	std::shared_ptr<IView> m_pView;
};

#endif //IPRESENTER_H
