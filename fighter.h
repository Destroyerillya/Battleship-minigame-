//
// Created by Zver on 29.11.2017.
//

#ifndef LABASOLO4_FIGHTER_H
#define LABASOLO4_FIGHTER_H

#include "warplane.h"

using namespace warplane;

namespace fighter {
    class Fighter : public WarPlane {
    public:
        Fighter(){};
        Fighter(unsigned int HP,unsigned int SPD,unsigned int SCF, vec::vector <Armament> givenWeapon){
            health = HP;
            speed = SPD;
            scopeFuel = SCF;
            weapon = givenWeapon;
            type_plane = 1;
            countWeapons++;
            givenWeapon.clear();
        };
        ~Fighter(){};
    };
}

#endif //LABASOLO4_FIGHTER_H
