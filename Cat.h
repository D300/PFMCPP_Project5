#pragma once

#include "LeakedObjectDetector.h"

struct Cat
{    
    float hairLen = 0.3f;

    Cat();

    ~Cat();

    int teethStyle;
    bool healthy = true;
    int age = 4;
    float mood = 0.5f;
    
    void jump();
    void chill();
    void purrrr();

    float returnMood();
    void printMemberWithFunc();

    JUCE_LEAK_DETECTOR(Cat)
};
