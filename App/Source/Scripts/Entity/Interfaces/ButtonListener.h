#pragma once
#include "Builder.h"
class UIButton;

class IButtonListener
{
public:
	virtual void OnButtonClick(UIButton* button) = 0;
	virtual void OnButtonReleased(UIButton* button) = 0;

protected:
	IButtonListener() {}

};

