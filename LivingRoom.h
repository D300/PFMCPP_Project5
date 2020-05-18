#pragma once

#include <string>
#include "LeakedObjectDetector.h"

#include "Aquarium.h"

struct Cat;
struct LivingRoom
{
    Cat& cat;
    
    LivingRoom(Cat& cat_);
    ~LivingRoom();

    struct LeftCornerOfRoom
    {
        Aquarium& aOne, &aTwo;
        LeftCornerOfRoom(Aquarium& aOne_, Aquarium& aTwo_);
    };

    Aquarium aquaOneP, aquaTwoP;
    
    // where to put this guy?
    LeftCornerOfRoom leftCornerOfRoom { aquaOneP, aquaTwoP };

    std::string tryToCatchAFish();

    JUCE_LEAK_DETECTOR(LivingRoom)
};
