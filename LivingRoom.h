#pragma once

#include <string>
#include "LeakedObjectDetector.h"

#include "Aquarium.h"

struct Cat;
struct LivingRoom
{
    Cat& cat;
    Aquarium& aquaPlants, &aquaSharks;
    
    LivingRoom(Cat& cat_, Aquarium& aquaPlants_, Aquarium& aquaSharks_);
    ~LivingRoom();

    struct LeftCornerOfRoom
    {
        Aquarium& aquaPlants, &aquaSharks;
        LeftCornerOfRoom(Aquarium& aOne_, Aquarium& aTwo_);
    };

    LeftCornerOfRoom leftCornerOfRoom;

    std::string tryToCatchAFish();

    JUCE_LEAK_DETECTOR(LivingRoom)
};

/*
Remove this initializer of this member variable. 
You'll need to initialize leftCornerOfRoom in your LivingRoom's member initializer list by making use of your LivingRoom constructor's parameters.
*/
