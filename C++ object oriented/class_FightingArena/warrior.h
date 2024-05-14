#pragma once
#include <iostream>
#include "hero.h"

class Warrior : public Hero
{
private:
	int deffenseBuffTurns;
public:
	Warrior(const string name);
	virtual void SpecialSkill() override;
	virtual string GetName() override { return name; };
	void ReceiveDamage(int) override;
};
