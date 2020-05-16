#pragma once

#include "LeakedObjectDetector.h"

#include "Water.h"

struct Water;
struct Aquarium
{
    float size;

    Aquarium() : size(39)
    {
        std::cout << "aquarium ctor\n" << std::endl;
    }

    ~Aquarium()
    {
        std::cout << "aquarium destructor" << std::endl;
    }

    Water filterWaterUntilItsClean(Water water);

    JUCE_LEAK_DETECTOR(Aquarium)
};

Water Aquarium::filterWaterUntilItsClean(Water water)
{
    while (water.getCondition() < 0)
    {
        water.clarity += 5;
        std::cout << "...filters water..." << std::endl;
    }    
    return water;
}
