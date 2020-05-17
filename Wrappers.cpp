#include "Wrappers.h"

WaterWrapper::WaterWrapper(Water* ptr) : ptrToWater( ptr ) 
{ 

}

WaterWrapper::~WaterWrapper()
{
    delete ptrToWater;
}


FunWrapper::FunWrapper(Fun* ptr) : ptrToFun(ptr) 
{ 

}

FunWrapper::~FunWrapper()
{
    delete ptrToFun;
}


LivingRoomWrapper::LivingRoomWrapper(LivingRoom* livingRoom_) : 
livingRoom(livingRoom_) 
{

}
   
LivingRoomWrapper::~LivingRoomWrapper() 
{
    delete livingRoom;
}



CupWrapper::CupWrapper(Cup* cup_) :
cup(cup_)
{

}

CupWrapper::~CupWrapper()
{
    delete cup;
}

AquariumWrapper::AquariumWrapper(Aquarium* aquarium_) : 
aquarium(aquarium_)
{

}

AquariumWrapper::~AquariumWrapper()
{
    delete aquarium;
}

CatWrapper::CatWrapper(Cat* cat_) : 
cat(cat_)
{

}

CatWrapper::~CatWrapper()
{
    delete cat;
}
