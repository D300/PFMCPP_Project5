#pragma once

#include "LeakedObjectDetector.h"

struct Water;
struct WaterWrapper
{
    Water* ptrToWater = nullptr;
    
    WaterWrapper(Water* ptr);
    ~WaterWrapper();

    JUCE_LEAK_DETECTOR(WaterWrapper)
};

struct Fun;
struct FunWrapper
{
    Fun* ptrToFun = nullptr; 

    FunWrapper(Fun* ptr);
    ~FunWrapper();

    JUCE_LEAK_DETECTOR(FunWrapper)
};

struct LivingRoom;
struct LivingRoomWrapper
{
    LivingRoom* livingRoom = nullptr;
    
    LivingRoomWrapper(LivingRoom* livingRoom_);
    ~LivingRoomWrapper();
    
    JUCE_LEAK_DETECTOR(LivingRoomWrapper)
};
