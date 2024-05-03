#pragma once
using namespace std;
#include "Spell.h"

class HealingTouchSpell : public Spell {
    static const int HEALING = 8;

public:
    void Cast(Character& caster, Character& target);
    Spell* Clone() const override { return new HealingTouchSpell(*this); }
protected:
    void Serialize(ostream& os) const override;

};
