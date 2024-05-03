#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

Character::Character(const string& name, int max_health_points) :
	name(name), max_health_points(max_health_points), 
	current_health_points(max_health_points) {}

void Character::Attack(Character& character)
{
	cout << name << " attacks " << character.name << endl;
	character.TakeDamage();
}

void Character::Rest(int hours)
{
	cout << name << " rests for " << hours << " hours " << endl;
	this->GetHealed(hours);
}

void Character::TakeDamage(int damage)
{
	current_health_points -= damage;
	if (current_health_points < 0)
		current_health_points = 0;
	cout << name << " takes " << damage << " damage " << endl;
}

void Character::GetHealed(int heal)
{
	current_health_points += heal;
	if (current_health_points > max_health_points) {
		current_health_points = max_health_points;
	}
	cout << name << " heals " << heal << " health points" << endl;
}

void Character::Serialize(ostream& os) const {
	os << name << " (HP:" << current_health_points << "/" << max_health_points << ")";
}

ostream& operator<<(ostream& os, const Character& character) {
	character.Serialize(os);
	return os;
}