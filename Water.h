#pragma once

#include "LeakedObjectDetector.h"

struct Water
{
    float clarity = -50.f;
    
    Water(float c)  : clarity(c) 
    { 

    }

    ~Water()
    { 
        std::cout << "water destructor" << std::endl; 
    }  

    float getCondition()
    {
        return clarity;
    }

    JUCE_LEAK_DETECTOR(Water)
};
