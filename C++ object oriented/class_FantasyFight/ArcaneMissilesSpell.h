#pragma once

#include "Spell.h"

class ArcaneMissilesSpell : public Spell {
    static const int DAMAGE = 1;
    static const int MISSILES_COUNT = 3;
public:
    void Cast(Character& caster, Character& target) override;
    Spell* Clone() const override { return new ArcaneMissilesSpell(*this); }
protected:
    void Serialize(std::ostream& os) const override;

};
