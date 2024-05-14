#pragma once
#include <string>
#include <ostream>
using namespace std;

class Hero {
protected:
    string name;
    int health;
    int strength;
    int actionPoints;
    int skillAPCost;

public:
    Hero(const string name, int health,
        int strength, int actionPoints, int skillAPCost);
    virtual void SpecialSkill() = 0;
    virtual string GetName() = 0;
    int GetHP() { return health; };
    int GetStrength() { return strength; };
    int GetAP() { return actionPoints; };
    int GetSkillCost() { return skillAPCost; };

    virtual bool Attack(Hero*);
    virtual void Rest();
    virtual void ReceiveDamage(int);
    bool HasEnoughAP(int requestedAP) { return requestedAP <= actionPoints; };
    void DecreaseAP(int amount) { actionPoints -= amount; };
    void PrintStatus();
};