#include "LivingRoom.h"
    
LivingRoom::LivingRoom(Cat& cat_) : cat(cat_) 
{ 
    std::cout << "living room ctor\n" << std::endl;

    aquaOneP.size = 40;
    aquaTwoP.size = 60;
}

LivingRoom::~LivingRoom() 
{ 
    std::cout << "living room dtor\n" << std::endl;
}

std::string LivingRoom::tryToCatchAFish() 
{
    return "big_fish";
}

LivingRoom::LeftCornerOfRoom::LeftCornerOfRoom(Aquarium& aOne_, Aquarium& aTwo_) : 
aOne(aOne_), aTwo(aTwo_) 
{ 
    std::cout << "left corner of the room ctor\n" << std::endl;

    std::cout << "aOne size: " << aOne.size << "\n" << std::endl;
    std::cout << "aTwo size: " << aTwo.size << std::endl;
}

