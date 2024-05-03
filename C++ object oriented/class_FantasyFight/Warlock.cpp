#include "Warlock.h"
#include "HealingTouchSpell.h"
#include "ArcaneMissilesSpell.h"
#include <iostream>

Warlock::Warlock(const std::string& name, int max_health_points, int spell_slots)
    : Character(name, max_health_points), spell_slots(spell_slots), prepared_spells(0),
    spells(new Spell* [spell_slots]) 
{
    for (int i = 0; i < spell_slots; ++i) {
        spells[i] = nullptr;
    }
}

Warlock::~Warlock()
{
    for (int i = 0; i < spell_slots; i++) delete spells[i];
    delete[] spells;
}

void Warlock::Attack(Character& character)
{
    for (int i = 0; i < spell_slots; ++i)
    {
        if (spells[i] != nullptr)
        {
            spells[i]->Cast(*this, character);
            spells[i] = nullptr;
            prepared_spells--;
            return;;
        }
    }
    // If no spells prepared, attack according to normal rules
    Character::Attack(character);
}

void Warlock::Rest(int hours)
{
    Character::Rest(hours);
    PrepareSpell(hours);
}

void Warlock::TakeDamage(int damage)
{
    Character::TakeDamage(damage);
}

void Warlock::GetHealed(int heal) {
    Character::GetHealed(heal);
}

void Warlock::Serialize(std::ostream& os) const {
    Character::Serialize(os);
    os << " (Warlock)" << std::endl;
    os << "Prepared spells:" << std::endl;
    for (int i = 0; i < spell_slots; ++i) {
        if (spells[i] != nullptr) {
            os << "Slot " << i + 1 << ": " << *spells[i] << std::endl;
        }
        else {
            os << "Slot " << i + 1 << ": Empty" << std::endl;
        }
    }
}

void Warlock::PrepareSpell(int hours_rested)
{
    for (int i = 0; i < spell_slots; ++i)
    {
        if (spells[i] == nullptr)
        {
            if (hours_rested % 2 == 0)
            {
                spells[i] = new ArcaneMissilesSpell();
            }
            else
            {
                spells[i] = new HealingTouchSpell();
            }
            prepared_spells++;
            return;
        }
    }
}

Warlock* Warlock::Clone()
{
    Warlock* clone = new Warlock(name, max_health_points, spell_slots);
    for (int i = 0; i < spell_slots; ++i)
    {
        if (spells[i] != nullptr)
        {
            clone->spells[i] = spells[i]->Clone();
        }
    }
    clone->prepared_spells = prepared_spells;
    clone->current_health_points = current_health_points;
    return clone;
}