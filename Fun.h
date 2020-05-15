#pragma once

#include "LeakedObjectDetector.h"

#include "Cat.h"

struct Fun
{
    Fun() 
    {
        std::cout << "fun ctor" << std::endl;
    }

    ~Fun() 
    { 
        // std::cout << "fun destructor" << std::endl;

        // cat.jump();
        // cup.fallFromTable(); 
    }

    void printFun()
    {
        std::cout << "fun-fun-fun" << std::endl;
    }

    Cat cat;

    JUCE_LEAK_DETECTOR(Fun)
};
