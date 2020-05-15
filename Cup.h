#pragma once

#include "LeakedObjectDetector.h"

struct Cup 
{
    int color = 1;

    Cup() { color = 2; }

    ~Cup() { std::cout << "cup destructor" << std::endl; }

    int material = 0;
    float size = 1.5f;
    bool dirty = false;
    float weigth = 5.0f;
    
    void stand();
    void breakCup();
    void fallFromTable();

    JUCE_LEAK_DETECTOR(Cup)
};

void Cup::stand() 
{
    std::cout << "cup stands" << std::endl;
}
void Cup::breakCup() 
{
    std::cout << "breakCup" << std::endl;
}
void Cup::fallFromTable() 
{
    std::cout << "fallFromTable - Art is a lie that makes us realize truth.\n" << std::endl;
}
