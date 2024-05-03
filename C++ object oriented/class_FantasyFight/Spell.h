#pragma once

#include <ostream>

class Character;

class Spell {

public:
    virtual ~Spell() = default;
    virtual void Cast(Character& caster, Character& target) = 0;
    virtual Spell* Clone() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Spell& spell);
protected:
    virtual void Serialize(std::ostream& os) const = 0;
};
