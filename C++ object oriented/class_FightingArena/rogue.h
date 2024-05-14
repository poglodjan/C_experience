#pragma once
#include <iostream>
#include "hero.h"

class Rogue : public Hero
{
private:
	bool stealth;
public:
	Rogue(const string name);
	virtual void SpecialSkill() override;
	virtual string GetName() override { return name; };
	void ReceiveDamage(int) override;
	bool Attack(Hero*) override;
};
