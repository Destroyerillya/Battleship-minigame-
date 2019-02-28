//
// Created by Zver on 28.11.2017.
//
#ifndef LABASOLO4_COMBATUNIT_H
#define LABASOLO4_COMBATUNIT_H

#include "mainhead.h"

using namespace std;

namespace combatunit {
    struct Armament {
        enum typeOfArmament {None = 0,Light = 1, Heavy = 1};
        typeOfArmament type;
        string nameOfArmament;
        string nameOfAmmunition;//vector names
        unsigned int ammunition;
        unsigned int damagePerSec;
        unsigned int rateOfFire;

        static typeOfArmament getTypeByNum(int currentType) {
            switch (currentType) {
                case 1:
                    return Light;
                    break;
                case 2:
                    return Heavy;
                    break;
                default:
                    break;
            }
            return None;
        };
    };

    class CombatUnit {
    public:
        unsigned int health;
        unsigned int speed;
        unsigned int scopeFuel;
        vec::vector<Armament> weapon;

        CombatUnit() {};
        ~CombatUnit() {};

    };
}
#endif //LABASOLO4_COMBATUNIT_H
