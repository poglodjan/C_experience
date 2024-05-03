#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(const string& name, int max_health_points, int shield_durability)
	: Character(name, max_health_points), shield_durability(shield_durability) {};

void Warrior::Rest(int hours)
{
	max_health_points++;
	Character::Rest(hours);
}

void Warrior::TakeDamage(int damage)
{
	if (shield_durability > 0)
	{
		shield_durability--;
		cout << name << " blocks the attack with their shield! " << endl;
	}
	else
	{
		Character::TakeDamage(damage);
	}
}

void Warrior::Serialize(std::ostream& os) const {
	Character::Serialize(os);
	os << " class: Warrior(" << shield_durability << ")";
}

void Warrior::Attack(Character& character)
{
	// Check if the target is also a Warrior
	Warrior* targetWarrior = dynamic_cast<Warrior*>(&character);
	if (targetWarrior)
	{
		while (targetWarrior->shield_durability > 0)
		{
			targetWarrior->shield_durability--;
			cout << targetWarrior->name << "'s shield durability reduced to "
				<< targetWarrior->shield_durability << std::endl;
		}
	}
	Character::Attack(character);
}