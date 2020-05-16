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
