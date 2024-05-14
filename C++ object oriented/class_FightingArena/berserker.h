#pragma once
#include <iostream>
#include "hero.h"

class Berserk : public Hero
{
private:
	bool buff;
public:
	Berserk(const string name);
	virtual void SpecialSkill() override;
	virtual string GetName() override { return name; };
	bool Attack(Hero*) override;
};
