#pragma once
#include "Builder.h"
class BigRingAnimation: public Core::AbstractComponent
{
public:
    BigRingAnimation(const std::string& name);
    virtual void perform() override;
    void reset();


private:
    int currentIndex = 0;
    float m_Ticks = 0.0f;
    
};

