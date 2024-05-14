#pragma once
#include <iostream>
#include "hero.h"

class Arena {
private:
    Hero* attackingHero;
    Hero* defendingHero;

    void PrintWelcomeMessage()
    {
        std::cout << "Welcome to the arena! Today, two of our mighty heroes begin the tournament for the title of the King of the arena! " << std::endl;
        std::cout << "Please welcome our heroes with a big applause:" << std::endl;

        std::cout << "----------------------------------------------------" << std::endl;
        // TODO Add proper fields in class to print status of fighting heroes
        //attackingHero->PrintStatus();
        //defendingHero->PrintStatus();

        std::cout << "----------------------------------------------------" << std::endl << std::endl;
        std::cout << "Who will be the mightiest? Who will be the King? Let's find out! FIGHT!" << std::endl;
    }

    void GameOver()
    {
        std::cout << "Mighty " << defendingHero->GetName() << " has fallen! " << std::endl;
        std::cout << "The Glorious " << attackingHero->GetName() << " becomes the New King of the arena! " << std::endl;

    }

    // TODO Implement necessary functions and fields

public:
    Arena(Hero* attackingHero, Hero* defendingHero, int seed);
    ~Arena() = default;
    void Simulate();
};
