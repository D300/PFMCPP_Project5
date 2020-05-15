#pragma once

#include "LeakedObjectDetector.h"


struct Aquarium;
struct Cat;
struct LivingRoom
{
    Cat& cat;
    
    LivingRoom(Cat& cat_) : cat(cat_) { }
    ~LivingRoom() { }

    struct LeftCornerOfRoom
    {
        Aquarium& aOne, &aTwo;
        LeftCornerOfRoom(Aquarium& aOne_, Aquarium& aTwo_) : aOne(aOne_), aTwo(aTwo_) { }
    };

    Aquarium aquaOneP, aquaTwoP;
    LeftCornerOfRoom leftCornerOfRoom { aquaOneP, aquaTwoP };

    void tryToCatchAFish();

    JUCE_LEAK_DETECTOR(LivingRoom)
};
