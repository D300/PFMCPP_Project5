#pragma once

#include "LeakedObjectDetector.h"

struct Cup 
{
    int color = 1;

    Cup();
    ~Cup();

    int material = 0;
    float size = 1.5f;
    bool dirty = false;
    float weigth = 5.0f;
    
    void stand();
    void breakCup();
    void fallFromTable();

    JUCE_LEAK_DETECTOR(Cup)
};

