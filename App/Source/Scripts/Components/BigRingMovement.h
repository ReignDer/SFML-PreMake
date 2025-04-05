#pragma once
#include "Builder.h"

class BigRingMovement : public Core::AbstractComponent
{
public:
    BigRingMovement(const std::string& name);
    virtual void perform() override;
    void configure(float delay);
    void reset();

private:
    const float SPEED = 200.f;
    
    float m_Ticks = 0.0f;
    float m_Delay = 0.0f;
};
