#include "Water.h"

Water::Water(float c)  : clarity(c) 
{ 

}

Water::~Water()
{ 
    std::cout << "water destructor" << std::endl; 
}  

float Water::getCondition()
{
    return clarity;
}
