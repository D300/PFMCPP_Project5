/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main to use your wrapper classes, which have your UDTs as pointer member variables.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example
 */




#include <iostream>

/*
 copied UDT 1:
 */

namespace Part5 {

struct Water
{
    float clarity = -50.f;
    Water(float c) : clarity(c) { }

    ~Water() { std::cout << "water destructor" << std::endl; }

    float getCondition()
    {
        return clarity;
    }
};

struct Aquarium
{
    float size;

    Aquarium() :
    size(39)
    {
        std::cout << "aquarium ctor\n" << std::endl;
    }

    ~Aquarium() { std::cout << "aquarium destructor" << std::endl; }

    Water filterWaterUntilItsClean(Water water);
};

Water Aquarium::filterWaterUntilItsClean(Water water)
{

    while (water.getCondition() < 0)
    {
        water.clarity += 5;
        std::cout << "...filters water..." << std::endl;
    }
    
    return water;
}

int main()
{
    Aquarium aquarium;
    Water water(-50);
    
    auto filteredWater = aquarium.filterWaterUntilItsClean(water);

    std::cout << "\nwater is clean with a clarity of " << filteredWater.clarity << "\n" << std::endl;

    return 0;
}

} // end namespace


/*
 copied UDT 2:
 */

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

/*
 copied UDT 3:
 */

struct Cup 
{
    int color = 1;

    Cup() { color = 2; }

    ~Cup() { std::cout << "cup destructor" << std::endl; }

    int material = 0;
    float size = 1.5f;
    bool dirty = false;
    float weigth = 5.0f;
    
    void stand();
    void breakCup();
    void fallFromTable();
};

void Cup::stand() 
{
    std::cout << "stand" << std::endl;
}
void Cup::breakCup() 
{
    std::cout << "breakCup" << std::endl;
}
void Cup::fallFromTable() 
{
    std::cout << "fallFromTable - Art is a lie that makes us realize truth.\n" << std::endl;
}

/*
 new UDT 4:
 */
struct LivingRoom
{
    LivingRoom() 
    {
        std::cout << "LivingRoom ctor" << std::endl;
    }
    ~LivingRoom() 
    {
        std::cout << "LivingRoom dtor" << std::endl;
    }
    
    Part5::Aquarium aquarium;
    Cat cat;

    void tryToCatchAFish();
};


/*
 new UDT 5:
 */

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

    Cat cat;
    Cup cup;
 };


int main()
{
    Part5::Aquarium aquarium;
    Cat cat;
    Cup cup;
    
    cat.jump();
    cup.fallFromTable();
    
    LivingRoom livingRoom;
    Fun fun;

    // Project 5 Part 2
    std::cout << "\n====PROJECT 5 PART 2 START====" << std::endl;

    // 1
    std::cout << "cat´s age: " << cat.age << std::endl;
    std::cout << "cup´s weigth: " << cup.weigth << std::endl;

    // printing via this->
    cat.printMemberWithFunc(); 

    std::cout << "====PROJECT 5 PART 2 END====\n" << std::endl;

    std::cout << "good to go!\n" << std::endl;
}
