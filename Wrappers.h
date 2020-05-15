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
    // JUCE_LEAK_DETECTOR(Water)
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
};
