//
// Created by Zver on 29.11.2017.
//

#ifndef LABASOLO4_BOMBER_H
#define LABASOLO4_BOMBER_H

#include "warplane.h"

using namespace warplane;

namespace bomber {
    class Bomber : public WarPlane {
    public:
        Bomber(){};
        Bomber(unsigned int HP,unsigned int SPD,unsigned int SCF, vec::vector <Armament> givenWeapon){
            health = HP;
            speed = SPD;
            scopeFuel = SCF;
            weapon = givenWeapon;
            type_plane = 2;
            countWeapons++;
            givenWeapon.clear();
        };
        ~Bomber(){};
    };
}

#endif //LABASOLO4_BOMBER_H
