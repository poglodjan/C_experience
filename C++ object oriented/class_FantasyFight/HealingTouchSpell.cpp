#include "HealingTouchSpell.h"
#include "character.h"

void HealingTouchSpell::Cast(Character& caster, Character& target) {
    target.GetHealed(HEALING);
}

void HealingTouchSpell::Serialize(std::ostream& os) const {
    os << "Healing Touch Spell";
}
