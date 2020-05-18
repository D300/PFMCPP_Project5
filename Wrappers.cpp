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
livingRoom(livingRoom_) 
{

}
   
LivingRoomWrapper::~LivingRoomWrapper() 
{
    delete livingRoom;
    livingRoom = nullptr;
}



CupWrapper::CupWrapper(Cup* cup_) :
cup(cup_)
{

}

CupWrapper::~CupWrapper()
{
    delete cup;
    cup = nullptr;
}

AquariumWrapper::AquariumWrapper(Aquarium* aquarium_) : 
aquarium(aquarium_)
{

}

AquariumWrapper::~AquariumWrapper()
{
    delete aquarium;
    aquarium = nullptr;

}

CatWrapper::CatWrapper(Cat* cat_) : 
cat(cat_)
{

}

CatWrapper::~CatWrapper()
{
    delete cat;
    cat = nullptr;
}
