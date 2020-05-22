#include "LivingRoom.h"
    
LivingRoom::LivingRoom(Cat& cat_, Aquarium& aquaPlants_, Aquarium& aquaSharks_) :
cat(cat_),
aquaPlants(aquaPlants_),
aquaSharks(aquaSharks_),
leftCornerOfRoom(aquaPlants_, aquaSharks_) 
// <<<<<< this initializes leftCornerOfRoom with your constructor parameters
// FIXME you need to initialize your leftCornerOfRoom member with your ctor parameters
{ 
    std::cout << "living room ctor\n" << std::endl;

    aquaPlants.size = 40;
    aquaSharks.size = 60;
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
aquaPlants(aOne_), 
aquaSharks(aTwo_) 
{ 
    std::cout << "left corner of the room ctor\n" << std::endl;

    std::cout << "aOne size: " << aquaPlants.size << "\n" << std::endl;
    std::cout << "aTwo size: " << aquaSharks.size << std::endl;
}

