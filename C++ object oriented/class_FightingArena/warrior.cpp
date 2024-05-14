#include "warrior.h"

Warrior::Warrior(const string name) :
	Hero("Warrior " + name, 12, 2, 2, 2),
	deffenseBuffTurns(0)
{
}

void Warrior::SpecialSkill()
{
	if (HasEnoughAP(skillAPCost))
	{
		deffenseBuffTurns = 2;
		DecreaseAP(2);
	}
	else cout << "Not enough AP";
}

void Warrior::ReceiveDamage(int dmg)
{
	if (deffenseBuffTurns > 0)
	{
		dmg -= 1;
		deffenseBuffTurns -= 1;
	}
	Hero::ReceiveDamage(dmg);
}
