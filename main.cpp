/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}



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
    
    LivingRoom livingRoom;
    Fun fun;

    std::cout << "good to go!" << std::endl;
}
