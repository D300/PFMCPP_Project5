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

#include "Water.h"
#include "Aquarium.h"
#include "Cat.h"
#include "Cup.h"
#include "Fun.h"
#include "LivingRoom.h"

#include "Wrappers.h"

/*
 These instances need to be Wrapped instances.
 Make your LivingRoom::leftCornerOfRoom use these Aquarium instances that are wrapped instead of the ones that are LivingRoom class members.
 you'll need to modify your LivingRoom constructor in order to initialize the leftCornerOfRoom member variable
*/


int main()
{
    AquariumWrapper aWPlants ( new Aquarium(20) ); 
    AquariumWrapper aWSharks ( new Aquarium (40) );
    
    Cat cat;
    Cup cup;

    WaterWrapper wW (new Water(15.f));
    std::cout << "water´s condition: " << wW.ptrToWater->getCondition() << std::endl;
    
    FunWrapper fW (new Fun());
    fW.ptrToFun->printFun();
    
    auto* aWPlantPtr = aWPlants.ptrToAquarium;
    auto* aWSharksPtr = aWSharks.ptrToAquarium;

    LivingRoomWrapper lRW ( new LivingRoom(cat, *aWPlantPtr, *aWSharksPtr));
    
    std::cout << "livingRoomWrapper: " << lRW.ptrToLivingRoom->tryToCatchAFish() << "\n";
    lRW.ptrToLivingRoom->cat.purrrr();
    

    // after challenge:
    std::cout << "aquarium size: " << lRW.ptrToLivingRoom->leftCornerOfRoom.aquaPlants.getSize() << "  " << std::endl;

    if (&lRW.ptrToLivingRoom->aquaPlants == &lRW.ptrToLivingRoom->leftCornerOfRoom.aquaPlants)
    {
        std::cout << "they're the same object" << std::endl;
    }
    
    LivingRoom livingRoom (cat, *aWPlantPtr, *aWSharksPtr);

    if (&livingRoom.aquaPlants == &lRW.ptrToLivingRoom->leftCornerOfRoom.aquaPlants)
    {
        std::cout << "they're the same object tooo" << std::endl;
    }

    std::cout << "good to go!\n" << std::endl;
}
