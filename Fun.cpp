#include "Fun.h"

Fun::Fun() 
{
    std::cout << "fun ctor" << std::endl;
}

Fun::~Fun() 
{ 
        // std::cout << "fun destructor" << std::endl;

        // cat.jump();
        // cup.fallFromTable(); 
}

void Fun::printFun()
{
    std::cout << "fun-fun-fun" << std::endl;
}
