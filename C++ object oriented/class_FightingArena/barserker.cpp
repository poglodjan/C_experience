#include "berserker.h"

Berserk::Berserk(const string name) :
	Hero("Berserk " + name, 10, 3, 2, 2),
	buff(false)
{
}

void Berserk::SpecialSkill()
{
	if (HasEnoughAP(skillAPCost))
	{
		buff = true;
		health -= 2;
		DecreaseAP(2);
	}
	else cout << "Not enough AP";
}

bool Berserk::Attack(Hero* opponent)
{
	if (buff)
	{
		strength += 2;
		if (Hero::Attack(opponent))
		{
			buff = false;
			strength -= 2;
			return true;
		}
	}
	else return Hero::Attack(opponent);
}




