#include <iostream>
#include "hero.h"
#include "arena.h"
#include "warrior.h"
#include "berserker.h"
#include "rogue.h"

using namespace std;

void DeleteArray(Hero** h, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete h[i];
    }
    delete[] h;
}

void TestSkills()
{
    Hero** testSkillHeroes = new Hero * [3];
    testSkillHeroes[0] = new Warrior("Hercules");;
    testSkillHeroes[1] = new Rogue("Sebille");
    testSkillHeroes[2] = new Berserk("Conan");

    // Only 1 HP is taken upon using Skill
    std::cout << "--TEST-WARRIOR--" << std::endl;
    testSkillHeroes[0]->PrintStatus();
    testSkillHeroes[1]->Attack(testSkillHeroes[0]);
    testSkillHeroes[0]->SpecialSkill();
    testSkillHeroes[0]->PrintStatus();
    testSkillHeroes[1]->Attack(testSkillHeroes[0]);
    testSkillHeroes[0]->PrintStatus();
    //
    //    // Only 1 HP is taken upon using Skill
    std::cout << "--TEST-BERSERK--" << std::endl;
    testSkillHeroes[2]->PrintStatus();
    testSkillHeroes[2]->Rest();
    testSkillHeroes[2]->PrintStatus();
    testSkillHeroes[1]->PrintStatus();
    testSkillHeroes[2]->Attack(testSkillHeroes[1]);
    testSkillHeroes[2]->SpecialSkill();
    testSkillHeroes[1]->PrintStatus();
    testSkillHeroes[2]->Attack(testSkillHeroes[1]);
    testSkillHeroes[1]->PrintStatus();
    testSkillHeroes[2]->PrintStatus();
    //
    std::cout << "--TEST-ROGUE--" << std::endl;
    testSkillHeroes[1]->PrintStatus();
    testSkillHeroes[1]->Rest();
    testSkillHeroes[1]->PrintStatus();
    testSkillHeroes[1]->SpecialSkill();
    testSkillHeroes[2]->Attack(testSkillHeroes[1]);
    testSkillHeroes[1]->PrintStatus();
    testSkillHeroes[2]->Attack(testSkillHeroes[1]);
    testSkillHeroes[1]->PrintStatus();
    testSkillHeroes[2]->PrintStatus();
    testSkillHeroes[1]->Attack(testSkillHeroes[2]);
    testSkillHeroes[2]->PrintStatus();
    //
    DeleteArray(testSkillHeroes, 3);
}

int main()
{
    // Part 1
    // Below line uncommented should give warning.
    // Hero* hero = new Hero("Clive");

    // Part 2
    std::cout << "-------------------------PART 2---------------------------" << std::endl;
    Hero** testHeroes = new Hero * [3];
    testHeroes[0] = new Warrior("Hercules");;
    testHeroes[1] = new Rogue("Sebille");
    testHeroes[2] = new Berserk("Conan");

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Hero name: " << testHeroes[i]->GetName() << std::endl;
        std::cout << "Hero HP: " << testHeroes[i]->GetHP() << std::endl;
        std::cout << "Hero strength: " << testHeroes[i]->GetStrength() << std::endl;
        std::cout << "Hero AP: " << testHeroes[i]->GetAP() << std::endl;
        std::cout << "Hero Skill Cost: " << testHeroes[i]->GetSkillCost() << std::endl;
        testHeroes[i]->PrintStatus();
        std::cout << "----------------------------------------------------" << std::endl;
    }

    // Part 3
    std::cout << "-------------------------PART 3--------------------------" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        testHeroes[0]->Attack(testHeroes[2]);
        testHeroes[0]->PrintStatus();
        testHeroes[2]->PrintStatus();
    }
    testHeroes[1]->PrintStatus();
    testHeroes[1]->ReceiveDamage(10);
    testHeroes[1]->PrintStatus();
    testHeroes[1]->Rest();
    testHeroes[1]->PrintStatus();

    DeleteArray(testHeroes, 3);

    // Part 4
    std::cout << "-------------------------PART 4--------------------------" << std::endl;
    TestSkills();

    // Part 5
    std::cout << "-------------------------PART 5--------------------------" << std::endl;
    TestSkills();

    // Part 6
    std::cout << "-------------------------PART 6--------------------------" << std::endl;
        Hero* mightyWarrior = new Warrior("Alexander The Fighting Jar");
        Hero* madBerserk = new Berserk("Ragnar");
        Arena warriorVsBerserkArena(mightyWarrior, madBerserk, 44);
    
        warriorVsBerserkArena.Simulate();

        // Part 7
    //    Hero* righteousPaladin = new Warrior("Roland");
    //    Hero* stealthyRogue = new Rogue("Ezio");
    //    Arena warriorVsRogueArena(righteousPaladin, stealthyRogue, 73);
    //
    //    warriorVsRogueArena.Simulate();
}

