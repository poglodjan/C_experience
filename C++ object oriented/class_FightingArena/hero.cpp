#include "hero.h"
#include <iostream>

Hero::Hero(const string name, int health = 10,
	int strength = 2, int actionPoints = 2, int skillAPCost = 2) :
	name(name), health(health), strength(strength),
	actionPoints(actionPoints), skillAPCost(skillAPCost)
{
}

bool Hero::Attack(Hero* opponent)
{
	if (HasEnoughAP(1))
	{
		opponent->ReceiveDamage(strength);
		DecreaseAP(1);
		return true;
	}
	return false;
}

void Hero::Rest()
{
	actionPoints += 3;
}

void Hero::ReceiveDamage(int dmg)
{
	health = health - dmg;
}

void Hero::PrintStatus()
{
	cout << name << ", HP: " << GetHP() << ", Strength: " << GetStrength() <<
		", Action Points: " << GetAP() << endl;
}

