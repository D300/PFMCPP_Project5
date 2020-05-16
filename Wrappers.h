#pragma once

#include "LeakedObjectDetector.h"

struct Water;
struct WaterWrapper
{
    Water* ptrToWater = nullptr;
    
    WaterWrapper(Water* ptr) : ptrToWater( ptr ) { }
    ~WaterWrapper()
    {
        delete ptrToWater;
    }
    JUCE_LEAK_DETECTOR(WaterWrapper)
};

struct Fun;
struct FunWrapper
{
    Fun* ptrToFun = nullptr; 

    FunWrapper(Fun* ptr) : ptrToFun(ptr) { }

    ~FunWrapper()
    {
        delete ptrToFun;
    }
    JUCE_LEAK_DETECTOR(FunWrapper)
};

struct LivingRoom;
struct LivingRoomWrapper
{
    LivingRoom* livingRoom = nullptr;
    
    LivingRoomWrapper(LivingRoom* livingRoom_) : livingRoom(livingRoom_) {}
    ~LivingRoomWrapper() 
    {
        delete livingRoom;
    }
    JUCE_LEAK_DETECTOR(LivingRoomWrapper)
};
