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
    LivingRoom* ptrToLivingRoom = nullptr;
    
    LivingRoomWrapper(LivingRoom* livingRoom_);
    ~LivingRoomWrapper();
    
    JUCE_LEAK_DETECTOR(LivingRoomWrapper)
};

struct Cup;
struct CupWrapper
{
    Cup* ptrToCup = nullptr;

    CupWrapper(Cup* cup_);
    ~CupWrapper();

    JUCE_LEAK_DETECTOR(CupWrapper)
};

struct Aquarium;
struct AquariumWrapper
{
    Aquarium* ptrToAquarium = nullptr;

    AquariumWrapper(Aquarium* aquarium_);
    ~AquariumWrapper();

    JUCE_LEAK_DETECTOR(AquariumWrapper)
};

struct Cat;
struct CatWrapper
{
    Cat* ptrToCat = nullptr;

    CatWrapper(Cat* cat_);
    ~CatWrapper();

    JUCE_LEAK_DETECTOR(CatWrapper)
};
