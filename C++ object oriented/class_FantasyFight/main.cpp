#include <iostream>

#include "Character.h"
#include "Warrior.h"
#include "Warlock.h"
#include "Spell.h"
#include "ArcaneMissilesSpell.h"
#include "HealingTouchSpell.h"

int main() {

    std::cout << "\n******************* PART 1 *******************\n\n";

    Character* valeera = new Character{"Valeera", 9};
    Character* anduin = new Character{"Anduin", 7};

    std::cout << *valeera << std::endl;
    std::cout << *anduin << std::endl << std::endl;

    valeera->Attack(*anduin);
    anduin->Attack(*valeera);

    for (int i = 0; i < 3; ++i)
        valeera->Attack(*anduin);

    anduin->Attack(*valeera);

    std::cout << *valeera << std::endl;
    std::cout << *anduin << std::endl << std::endl;

    anduin->Rest(6);
    anduin->Attack(*valeera);

    std::cout << *valeera << std::endl;
    std::cout << *anduin << std::endl;

    std::cout << "\n******************* PART 2 *******************\n\n";

    Character* garrosh = new Warrior{"Garrosh", 6, 2};

    std::cout << *garrosh << std::endl << std::endl;

    valeera->Attack(*garrosh);
    anduin->Attack(*garrosh);

    std::cout << *garrosh << std::endl << std::endl;

    valeera->Attack(*garrosh);
    anduin->Attack(*garrosh);

    garrosh->Rest(1);

    std::cout << *garrosh << std::endl;

    std::cout << "\n******************* PART 3 *******************\n\n";

    Character* magni = new Warrior{"Magni", 6, 3};

    std::cout << *magni << std::endl << std::endl;

    garrosh->Attack(*magni);
    anduin->Attack(*magni);
    valeera->Attack(*magni);
    magni->Attack(*garrosh);

    std::cout << *magni << std::endl;
    std::cout << *garrosh << std::endl;

    std::cout << "\n******************* PART 4 *******************\n\n";

    Character* d1 = new Character{"Dummy1", 8};
    Character* d2 = new Character{"Dummy2", 10};

    Spell* s1 = new ArcaneMissilesSpell();
    Spell* s2 = new HealingTouchSpell();

    std::cout << *s1 << std::endl;
    std::cout << *s2 << std::endl << std::endl;

    for (int i = 0; i < 3; ++i)
        s1->Cast(*d1, *d2);
    s2->Cast(*d2, *d2);

    std::cout << *d1 << std::endl;
    std::cout << *d2 << std::endl;

    std::cout << "\n******************* PART 5 *******************\n\n";

    Character* guldan =  new Warlock{"Gul'dan", 8, 2};
    Character* tamsin = new Warlock{"Tamsin", 7, 4};

    std::cout << *guldan << std::endl;
    std::cout << *tamsin << std::endl << std::endl;

    guldan->Rest(0);
    guldan->Rest(0);
    guldan->Rest(1);
    tamsin->Rest(0);
    tamsin->Rest(1);
    tamsin->Rest(0);

    std::cout << *guldan << std::endl;
    std::cout << *tamsin << std::endl << std::endl;

    guldan->Attack(*tamsin);
    tamsin->Attack(*guldan);
    tamsin->Attack(*tamsin);
    guldan->Attack(*tamsin);
    guldan->Attack(*tamsin);

    std::cout << *guldan << std::endl;
    std::cout << *tamsin << std::endl;

    std::cout << "\n******************* PART 6 *******************\n\n";

    guldan->Rest(1);
    guldan->Rest(0);
    guldan->Rest(1);

    std::cout << *guldan << std::endl << std::endl;

    Character* guldan_clone = dynamic_cast<Warlock*>(guldan)->Clone();

    std::cout << *guldan_clone << std::endl;

    /********** CLEAN UP **********/
    delete valeera; delete anduin;
    delete garrosh;
    delete magni;
    delete d1; delete d2; delete s1; delete s2;
    delete guldan; delete tamsin;
    delete guldan_clone;

    return 0;
}
