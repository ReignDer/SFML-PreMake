#pragma once

#include"Core/Core.h"
#include "Core/Input.h"

namespace Core {
	class WindowsInput : public Input
	{
	protected:
		virtual bool MouseButtonPressedImpl(int pressed) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}

