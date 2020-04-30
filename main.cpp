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

    // JUCE_LEAK_DETECTOR(Water)
};

struct WaterWrapper
{
    Water* ptrToWater = nullptr;
    
    WaterWrapper(Water* ptr) : ptrToWater( ptr ) { }
    ~WaterWrapper()
    {
        delete ptrToWater;
    }
    // JUCE_LEAK_DETECTOR(Water)
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

    // JUCE_LEAK_DETECTOR(Aquarium)
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

    // JUCE_LEAK_DETECTOR(Cat)
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

    // JUCE_LEAK_DETECTOR(Cup)
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
    struct Nested
    {
        B& b1, &b2;  //Nested depends on two B instances
        Nested(B& _1, B& _2) : b1(_1), b2(_2) { }
    };
    
    MyUDT_1(A& _a_, C* _c_) : a(_a_), c(_c_) { }
    A& a; //MyUDT_1 depends on an instance of A
    C* c = nullptr;
    
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
    struct LeftCornerOfRoom
    {
        Aquarium& a1, &a2;  //Nested depends on two B instances
        LeftCornerOfRoom(Aquarium& aOne_, Aquarium& aTwo_) : a1(aOne_), a2(aTwo_) { }
    };
    
    // i put those vars here because I init them in the ctor
    Aquarium* aquarium = nullptr;
    Cat& cat;

    LivingRoom(Cat& cat_, Aquarium* aquarium_) : cat(cat_), aquarium(aquarium_) { }
    ~LivingRoom() { }


    // i cant refer to a practical situation thats why I dont no if dereferencing makes sense then but practically I need an object in this ctor, not a ptr
    LeftCornerOfRoom leftCornerOfRoom { *aquarium, *aquarium };

    void tryToCatchAFish();

    // JUCE_LEAK_DETECTOR(LivingRoom)
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
    Cup cup;

    // JUCE_LEAK_DETECTOR(Fun)
 };

 struct FunWrapper
 {
    Fun* ptrToFun = nullptr; 
    
    FunWrapper(Fun* ptr) : ptrToFun(ptr) { }

    FunWrapper()
    {
        delete ptrToFun;
    }
 };


int main()
{
    Aquarium aquarium;
    Cat cat;
    Cup cup;
    
    cat.jump();
    cup.fallFromTable();
    
    LivingRoom livingRoom(cat, &aquarium);
    
    Fun fun;

    // Project 5 Part 2
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
    Water clearWater = Water(10.f);
    Water* ptrToClearWater = &clearWater;

    auto* wW = new WaterWrapper(ptrToClearWater);
    std::cout << "water´s condition: " << wW->ptrToWater->getCondition() << std::endl;

    Fun* ptrToFun = &fun;
    auto* fW = new FunWrapper(ptrToFun);
    fW->ptrToFun->printFun();

    


    /*
     here's the wrapper class usage, from the 'new' video
     */
    LivingRoomWrapper livingRoomWrapper( new LivingRoom(cat, &aquarium) );
    
    if( &livingRoomWrapper.livingRoom->aquarium == &livingRoomWrapper.livingRoom->leftCornerOfRoom.a1 )
        std::cout << "they're the same object" << std::endl;

    
    /*
     here's the wrapper class usage, from the 'new' video
     */
    
    /*
    UDTWrapper udt1Wrapper( new MyUDT_1(a, &c) );
    
    if( &udt1Wrapper.udt1->b1 == &udt1Wrapper.udt1->nested.b1 )
        std::cout << "they're the same object" << std::endl;
    */


    std::cout << "good to go!\n" << std::endl;
}
