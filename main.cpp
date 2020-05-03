/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */






#include "LeakedObjectDetector.h"
#include <iostream>

/*
 copied UDT 1:
 */

// namespace Part5 {


struct Water
{
    float clarity = -50.f;
    Water(float c) : clarity(c) { }

    ~Water() 
    { 
        std::cout << "water destructor" << std::endl; 
    }

    float getCondition()
    {
        return clarity;
    }

    JUCE_LEAK_DETECTOR(Water)
};

struct WaterWrapper
{
    Water* ptrToWater = nullptr;
    
    WaterWrapper(Water* ptr) : ptrToWater( ptr ) { }
    ~WaterWrapper()
    {
        delete ptrToWater;
    }
    JUCE_LEAK_DETECTOR(Water)
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

    JUCE_LEAK_DETECTOR(Aquarium)
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

/*
int main()
{
    Aquarium aquarium;
    Water water(-50);
    
    auto filteredWater = aquarium.filterWaterUntilItsClean(water);

    std::cout << "\nwater is clean with a clarity of " << filteredWater.clarity << "\n" << std::endl;

    // WaterWrapper ww(water);

    return 0;
}
*/

// } // end namespace Part5


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

    JUCE_LEAK_DETECTOR(Cup)
};

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

/*
struct MyUDT_1 //My class def from the 'this' video that depends on some other UDTs
{
    MyUDT_1(A& _a_, C* _c_) : a(_a_), c(_c_) { }
    A& a; //MyUDT_1 depends on an instance of A
    C* c = nullptr;
       
    struct Nested
    {
        B& b1, &b2;  //Nested depends on two B instances
        Nested(B& _1, B& _2) : b1(_1), b2(_2) { }
    };

    B b1, b2;
    Nested nested{ b1, b2 }; //'nested' depends on b1 and b2
    
    JUCE_LEAK_DETECTOR(MyUDT_1) // <-- added the leak detector
};

struct UDTWrapper
{
    UDTWrapper(MyUDT_1* _udt) : udt1(_udt) { }
    ~UDTWrapper() { delete udt1; }
    MyUDT_1* udt1 = nullptr;
};
*/


/*
 new UDT 4:
 */
struct LivingRoom
{
    /*
    MyUDT_1(A& _a_, C* _c_) : a(_a_), c(_c_) { }
    A& a; //MyUDT_1 depends on an instance of A
    C* c = nullptr;
    */
    
    Cat& cat;
    
    LivingRoom(Cat& cat_) : cat(cat_) { }
    ~LivingRoom() { }


    struct LeftCornerOfRoom
    {
        Aquarium& aOne, &aTwo;  //Nested depends on two B instances
        LeftCornerOfRoom(Aquarium& aOne_, Aquarium& aTwo_) : aOne(aOne_), aTwo(aTwo_) { }
    };

    Aquarium aquaOneP, aquaTwoP;
    LeftCornerOfRoom leftCornerOfRoom { aquaOneP, aquaTwoP };


    void tryToCatchAFish();

    JUCE_LEAK_DETECTOR(LivingRoom)
};

struct LivingRoomWrapper
{
    LivingRoom* livingRoom = nullptr;
    
    LivingRoomWrapper(LivingRoom* livingRoom_) : livingRoom(livingRoom_) {}
    ~LivingRoomWrapper() 
    {
        delete livingRoom;
    }

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

    void printFun()
    {
        std::cout << "fun-fun-fun" << std::endl;
    }

    Cat cat;

    JUCE_LEAK_DETECTOR(Fun)
};

struct FunWrapper
{
    Fun* ptrToFun = nullptr; 

    FunWrapper(Fun* ptr) : ptrToFun(ptr) { }

    ~FunWrapper()
    {
        delete ptrToFun;
    }
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    Aquarium aPlants, aSharks;
    Cat cat;

    /*
    std::cout << "\n====PROJECT 5 PART 2 START====" << std::endl;

    // 1
    std::cout << "cat´s age: " << cat.age << std::endl;
    std::cout << "cup´s weigth: " << cup.weigth << std::endl;

    // printing via this->
    cat.printMemberWithFunc(); 

    std::cout << "====PROJECT 5 PART 2 END====\n" << std::endl;
    */

    std::cout << "====PROJECT 5 PART 3 START====\n" << std::endl;


    // Part 3
    WaterWrapper wW (new Water(15.f));
    std::cout << "water´s condition: " << wW.ptrToWater->getCondition() << std::endl;

    FunWrapper fW ( new Fun());
    fW.ptrToFun->printFun();

    LivingRoomWrapper livingRoomWrapper( new LivingRoom(cat) );
    
    livingRoomWrapper.livingRoom->cat.purrrr();

    if (&livingRoomWrapper.livingRoom->aquaOneP == &livingRoomWrapper.livingRoom->leftCornerOfRoom.aOne)
    {
        std::cout << "they're the same object" << std::endl;
    }

    std::cout << "good to go!\n" << std::endl;
}
