#include "Cat.h"

Cat::Cat() 
{ 
    hairLen = 0.5f;
    std::cout << "cat ctor" << std::endl; 
}

Cat::~Cat() 
{ 
    std::cout << "cat destructor" << std::endl; 
}

float Cat::returnMood()
{
    return mood;
}

void Cat::printMemberWithFunc() 
{ 
    std::cout << "\nCat´s age in memberFunc: " << this->age << std::endl;
    std::cout << "Cat´s mood in memberFunc: " << this->returnMood() << std::endl;
}

void Cat::jump() 
{
    std::cout << "jump - Art washes away from the soul the dust of everyday life.\n" << std::endl;
}
void Cat::chill() 
{
    std::cout << "chill" << std::endl;
}
void Cat::purrrr() 
{
    std::cout << "purrrr" << std::endl;
}
