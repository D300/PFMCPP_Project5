#pragma once

#include "LeakedObjectDetector.h"

struct Water
{
    float clarity = -50.f;
    
    Water(float c);

    ~Water();

    float getCondition();

    JUCE_LEAK_DETECTOR(Water)
};
