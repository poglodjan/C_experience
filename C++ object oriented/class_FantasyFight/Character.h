#pragma once

#include <string>
#include <ostream>

class Character {

protected:
    std::string name;
    int max_health_points;
    int current_health_points;

public:
    Character() = delete;
    Character(const std::string& name, int max_health_points);
    virtual ~Character() = default;
    virtual void Attack(Character& character);
    virtual void Rest(int hours);
    virtual void TakeDamage(int damage=2);
    virtual void GetHealed(int heal);
    friend std::ostream& operator<<(std::ostream& os, const Character& character);
protected:
    virtual void Serialize(std::ostream& os) const;
};
