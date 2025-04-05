#pragma once
#include "Builder.h"
class SmallRingAnimation: public Core::AbstractComponent
{
public:
    SmallRingAnimation(const std::string& name);
    virtual void perform() override;
    void reset();


private:
    int currentIndex = 0;
    float m_Ticks = 0.0f;
};
