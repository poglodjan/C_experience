#pragma once

#include "Character.h"

class Warrior : public Character {

protected:
    int shield_durability;

public:
    Warrior() = delete;
    Warrior(const std::string& name, int max_health_points, int shield_durability);

    void Rest(int hours) override;
    void TakeDamage(int damage) override;
    void Attack(Character& character) override;
protected:
    void Serialize(std::ostream& os) const override;

public:
    //PART 6
    //Character* Clone();
};
