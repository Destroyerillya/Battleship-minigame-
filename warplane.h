//
// Created by Zver on 28.11.2017.
//

#ifndef LABASOLO4_WARPLANE_H
#define LABASOLO4_WARPLANE_H

#include "combatunit.h"

using namespace std;
using namespace combatunit;

namespace warplane{

    class WarPlane : public CombatUnit{
    public:
        unsigned int type_plane;
        unsigned int countWeapons = 0;

        WarPlane() {};
        ~WarPlane() {};

        int CheckoutArmament();
    };
}



#endif //LABASOLO4_WARPLANE_H
