/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3 and will take you through how to write code that doesn't leak as well as how to refactor. 

 Destructors

 If you didn't do Project3, write 3 UDTs below (where it asks for Copied UDTs) that have: 
        member functions,
        member variables, 
        constructors that initialize the members. 
        for() or while() loops that modify member variables
        
 Define your implementations of all functions OUTSIDE of the class. 
 Then do instruction 2)
 
 If you DID do Project 3, do instruction 1)
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 6) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
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

    while (water.getCondition() < 0) // a)
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
        std::cout << "fun dtor" << std::endl;

        cat.jump();
        cup.fallFromTable(); 
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
    
    std::cout << " " << std::endl;

    Part5::main();
    
    std::cout << "good to go!" << std::endl;

    LivingRoom livingRoom;
    Fun fun;
}
