#pragma once

#include "LeakedObjectDetector.h"

#include "Cat.h"

struct Fun
{
    Fun();
    ~Fun();

    void printFun();

    Cat cat;

    JUCE_LEAK_DETECTOR(Fun)
};
