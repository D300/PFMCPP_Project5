#pragma once

#include "LeakedObjectDetector.h"

#include "Water.h"

struct Aquarium
{
    float size;

    Aquarium();

    ~Aquarium();

    Water filterWaterUntilItsClean(Water water);

    JUCE_LEAK_DETECTOR(Aquarium)
};

