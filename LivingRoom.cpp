#include "LivingRoom.h"
    
LivingRoom::LivingRoom(Cat& cat_, Aquarium* ptrAquaOne_, Aquarium* ptrAquaTwo_) : 
cat(cat_),
ptrAquaOne(ptrAquaOne_), 
ptrAquaTwo(ptrAquaTwo_)
{ 
    std::cout << "living room ctor\n" << std::endl;

    ptrAquaOne->size = 40;
    ptrAquaTwo->size = 60;
}

LivingRoom::~LivingRoom() 
{ 
    std::cout << "living room dtor\n" << std::endl;
}

std::string LivingRoom::tryToCatchAFish() 
{
    return "big_fish";
}

LivingRoom::LeftCornerOfRoom::LeftCornerOfRoom(Aquarium* aquaOne_, Aquarium* aquaTwo_) : 
ptrAquaOneChild(aquaOne_), 
ptrAquaTwoChild(aquaTwo_) 
{ 
    std::cout << "left corner of the room ctor\n" << std::endl;

    std::cout << "aquaOne size: " << ptrAquaOneChild->size << "\n" << std::endl;
    std::cout << "aquaTwo size: " << ptrAquaTwoChild->size << std::endl;
}

