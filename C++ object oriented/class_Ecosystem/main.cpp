#include <iostream>
#include "organism.h"
#include "animal.h"
#include "fish.h"
#include "plant.h"
#include "rose.h"
#include "ecosystem.h"


int main() {

    //PART 1
    std::cout << "PART 1" << std::endl;
    Organism o1("organism");
    Organism o2("organism");
    std::cout << o1 << std::endl << o2 << std::endl;
    {
        Organism o3("organism");
        std::cout << o3 << std::endl;
    }
    std::cout << "current population: " << o1.population() << std::endl;


    //PART 2
    std::cout << std::endl << "PART 2" << std::endl;
    Animal a1("bear");
    std::cout << a1 << std::endl;
    const Organism &a2 = a1;
    std::cout << a2 << std::endl;
    Organism *a3 = new Animal("tiger");
    std::cout << *a3 << std::endl;
    delete a3;

    //PART 3
    std::cout << std::endl << "PART 3" << std::endl;
    Fish f1;
    std::cout << f1 << std::endl;
    Organism *f2 = new Fish();
    std::cout << *f2 << std::endl;
    delete f2;
    Animal *f3 = new Fish();
    std::cout << *f3 << std::endl;
    delete f3;


    //PART 4
    std::cout << std::endl << "PART 4" << std::endl;
    Plant p1("tree");
    std::cout << p1 << std::endl;
    std::cout << "We smell: " << p1.smell() << ". Well, it is hard to say what is it." << std::endl;
    Rose p2;
    std::cout << p2 << std::endl;
    std::cout << "We smell: " << p2.smell() << ". It smells exactly like the previous one. What is it?" << std::endl;
    std::cout << "Wait, now we smell: " << p2.smell(false) << ". This is probably a rose!" << std::endl;
    std::cout << "Oh, we smell: " << p2.smell(true) << ". This is definitelly a rose!!!" << std::endl;


    //PART 5
    std::cout << std::endl << "PART 5" << std::endl;
    Ecosystem ecosystem;
    // Incorrect    
    if(!ecosystem.initialize("bear#something :grass#plant::animal:frog")) {
        std::cout << "Incorrect data 1" << std::endl;
    }
    //Incorrect    
    if(!ecosystem.initialize("bear#animal:")) {
        std::cout << "Incorrect data 2" << std::endl;
    }
    //Incorrect    
    if(!ecosystem.initialize("bear#ANIMAL")) {
        std::cout << "Incorrect data 3" << std::endl;
    }
    //Incorrect    
    if(!ecosystem.initialize("animal#this # is correct:plant#this : is incorrect")) {
        std::cout << "Incorrect data 4" << std::endl;
    }
    //Incorrect    
    if(!ecosystem.initialize("bear#ani")) {
        std::cout << "Incorrect data 5" << std::endl;
    }
    //Incorrect    
    if(!ecosystem.initialize("#plant")) {
        std::cout << "Incorrect data 6" << std::endl;
    }
    //Incorrect    
    if(!ecosystem.initialize("plant")) {
        std::cout << "Incorrect data 7" << std::endl;
    }
    //Incorrect    
    if(!ecosystem.initialize("bear#")) {
        std::cout << "Incorrect data 8" << std::endl;
    }
    //Incorrect    
    if(!ecosystem.initialize("bear")) {
        std::cout << "Incorrect data 9" << std::endl;
    }
    //Correct
    if(!ecosystem.initialize("")) {
        std::cout << "Incorrect data 10" << std::endl;
    }
    //Correct
    if(!ecosystem.initialize("bear#animal:grass#plant:tree#plant:hibiscus#plant:frog#animal")) {
        std::cout << "Incorrect data 11" << std::endl;
    }

    return 0;
}
