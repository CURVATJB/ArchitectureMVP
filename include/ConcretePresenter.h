#pragma once

#include "ConcreteModel.h"
#include "ConcreteView.h"
#include "IPresenter.h"

class ConcretePresenter : public IPresenter<ConcreteModel, ConcreteView>
{
	
};