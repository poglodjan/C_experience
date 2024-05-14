#include "arena.h"
using namespace std;
Arena::Arena(Hero* _attackingHero, Hero* _defendingHero, int seed)
{
	srand(seed);
	int random = rand() % 2 + 1;
	if (random == 1)
	{
		attackingHero = _attackingHero;
		defendingHero = _defendingHero;
	}
	else
	{
		attackingHero = _defendingHero;
		defendingHero = _attackingHero;
	}
	PrintWelcomeMessage();
}

void Arena::Simulate()
{

	int action;

	do
	{
		cout << "Attacking Hero: " << endl;
		attackingHero->PrintStatus();
		cout << "1) Attack (" << attackingHero->GetStrength() << " AP)" << endl;
		cout << "2) Special Skill (" << attackingHero->GetSkillCost() << " AP)" << endl;
		cout << "3) Rest" << endl;
		cin >> action;
		switch (action)
		{
		case 1:
			if (attackingHero->Attack(defendingHero))
				cout<<"Attack done" << endl;
			else
				cout << "Attack not possible" << endl;
			break;
		case 2:
			attackingHero->SpecialSkill();
			break;
		case 3:
			attackingHero->Rest();
			break;
		default:
			cout << "Invalid action! Please choose a correct number." << endl;
		};
		swap(attackingHero, defendingHero);

	} while (attackingHero->GetHP()!=0);

	GameOver();
}
