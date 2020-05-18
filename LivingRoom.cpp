#include "LivingRoom.h"
    
LivingRoom::LivingRoom(Cat& cat_) : cat(cat_) 
{ 

}

LivingRoom::~LivingRoom() 
{ 

}

std::string LivingRoom::tryToCatchAFish() 
{
    return "big_fish";
}

LivingRoom::LeftCornerOfRoom::LeftCornerOfRoom(Aquarium& aOne_, Aquarium& aTwo_) : 
aOne(aOne_), aTwo(aTwo_) 
{ 

}

