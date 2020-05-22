#include "Aquarium.h"
#include "Cat.h"
#include "Cup.h"
#include "LivingRoom.h"
#include "Fun.h"
#include "Water.h"

#include "Wrappers.h"

WaterWrapper::WaterWrapper(Water* ptr) : ptrToWater( ptr ) 
{ 

}

WaterWrapper::~WaterWrapper()
{
    delete ptrToWater;
    ptrToWater = nullptr;
}


FunWrapper::FunWrapper(Fun* ptr) : ptrToFun(ptr) 
{ 

}

FunWrapper::~FunWrapper()
{
    delete ptrToFun;
    ptrToFun = nullptr;
}


LivingRoomWrapper::LivingRoomWrapper(LivingRoom* livingRoom_) : 
ptrToLivingRoom(livingRoom_) 
{

}
   
LivingRoomWrapper::~LivingRoomWrapper() 
{
    delete ptrToLivingRoom;
    ptrToLivingRoom = nullptr;
}



CupWrapper::CupWrapper(Cup* cup_) :
ptrToCup(cup_)
{

}

CupWrapper::~CupWrapper()
{
    delete ptrToCup;
    ptrToCup = nullptr;
}

AquariumWrapper::AquariumWrapper(Aquarium* aquarium_) : 
ptrToAquarium(aquarium_)
{

}

AquariumWrapper::~AquariumWrapper()
{
    delete ptrToAquarium;
    ptrToAquarium = nullptr;
}

CatWrapper::CatWrapper(Cat* cat_) : 
ptrToCat(cat_)
{

}

CatWrapper::~CatWrapper()
{
    delete ptrToCat;
    ptrToCat = nullptr;
}
