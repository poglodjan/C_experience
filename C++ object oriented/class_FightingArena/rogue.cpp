#include "rogue.h"
using namespace std;

Rogue::Rogue(const string name) :
	Hero("Rogue " + name, 10, 2, 3, 3),
	stealth(false)
{
}

void Rogue::SpecialSkill()
{
	if (HasEnoughAP(skillAPCost))
	{
		stealth = true;
		DecreaseAP(3);
	}
	else cout << "Not enough AP";
}

void Rogue::ReceiveDamage(int dmg)
{
	if (stealth)
	{
		dmg = 0;
	}
	Hero::ReceiveDamage(dmg);
}

bool Rogue::Attack(Hero* opponent)
{
	if (stealth)
	{
		strength = strength * 2;
		if (Hero::Attack(opponent)) 
		{
			stealth = false;
			strength = strength / 2;
			return true;
		}
	}
	else return Hero::Attack(opponent);
}

