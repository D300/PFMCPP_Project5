#pragma once

#include "LeakedObjectDetector.h"

#include "Water.h"

struct Aquarium
{
    float size;

    Aquarium(int size_);

    ~Aquarium();

    Water filterWaterUntilItsClean(Water water);

    int getSize() { return size; }

    JUCE_LEAK_DETECTOR(Aquarium)
};

