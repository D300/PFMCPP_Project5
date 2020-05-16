#include "Cup.h"


Cup::Cup() 
{ 
    color = 2; 
}

Cup::~Cup() 
{ 
    std::cout << "cup destructor" << std::endl; 
}

void Cup::stand() 
{
    std::cout << "cup stands" << std::endl;
}

void Cup::breakCup() 
{
    std::cout << "breakCup" << std::endl;
}

void Cup::fallFromTable() 
{
    std::cout << "fallFromTable - Art is a lie that makes us realize truth.\n" << std::endl;
}
