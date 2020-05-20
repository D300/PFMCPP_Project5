#pragma once

#include <string>
#include "LeakedObjectDetector.h"

#include "Aquarium.h"

struct Cat;
struct LivingRoom
{
    Cat& cat;
    
    // is line 14 and 16 the correct approach?
    Aquarium* ptrAquaOne, *ptrAquaTwo;
    
    LivingRoom(Cat& cat_, Aquarium* ptrAquaOne_, Aquarium* ptrAquaTwo_);
    ~LivingRoom();

    struct LeftCornerOfRoom
    {
        Aquarium* ptrAquaOneChild, *ptrAquaTwoChild;
        LeftCornerOfRoom(Aquarium* aquaOne_, Aquarium* aquaTwo_);
    };

    // where to put this guy?
    LeftCornerOfRoom leftCornerOfRoom { ptrAquaOne, ptrAquaTwo };

    std::string tryToCatchAFish();

    JUCE_LEAK_DETECTOR(LivingRoom)
};
