#include "Aquarium.h"

Aquarium::Aquarium() : size(39)
{
    std::cout << "aquarium ctor\n" << std::endl;
}

Aquarium::~Aquarium() 
{ 
    std::cout << "aquarium destructor" << std::endl; 
}

Water Aquarium::filterWaterUntilItsClean(Water water)
{
    while (water.getCondition() < 0)
    {
        water.clarity += 5;
        std::cout << "...filters water..." << std::endl;
    }
    return water;
}
