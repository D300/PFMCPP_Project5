#pragma once

#include "LeakedObjectDetector.h"

struct Cat
{    
    float hairLen = 0.3f;

    Cat() { hairLen = 0.5f; }

    ~Cat() { std::cout << "cat destructor" << std::endl; }

    int teethStyle;
    bool healthy = true;
    int age = 4;
    float mood = 0.5f;
    
    void jump();
    void chill();
    void purrrr();

    float returnMood()
    {
        return mood;
    }

    void printMemberWithFunc() 
	{ 
        std::cout << "\nCat´s age in memberFunc: " << this->age << std::endl;
        std::cout << "Cat´s mood in memberFunc: " << this->returnMood() << std::endl;
	}

    JUCE_LEAK_DETECTOR(Cat)
};

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
