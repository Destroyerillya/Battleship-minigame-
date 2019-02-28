//
// Created by Zver on 28.11.2017.
//

#ifndef LABASOLO4_WARSHIP_H
#define LABASOLO4_WARSHIP_H

#include "combatunit.h"
#include "warplane.h"

using namespace std;
using namespace combatunit;
using namespace warplane;

namespace warship {
    struct InfoAboutCap {
        string NameOurCapitan;
        enum rank {
            None = 0,
            Captain3rdRank = 1,
            Captain2rdRank = 2,
            Captain1rdRank = 3,
            RearAdmiral = 4,
            ViceAdmiral = 5,
            Admiral = 6
        };
        rank capitansRank;
        unsigned int experience;

        static rank getRankByNum(int currentRank) {
            switch (currentRank) {
                case 1:
                    return Captain3rdRank;
                    break;
                case 2:
                    return Captain2rdRank;
                    break;
                case 3:
                    return Captain1rdRank;
                    break;
                case 4:
                    return RearAdmiral;
                    break;
                case 5:
                    return ViceAdmiral;
                    break;
                case 6:
                    return Admiral;
                    break;
                default:
                    break;
            }
            return None;
        };
    };

    class WarShip : public CombatUnit {
    public:
        unsigned int numberOfCap = 0;
        string nameShip;
        unsigned int type_ship;
        unsigned int quantityOfCrewMembers;
        vec::vector <InfoAboutCap> FIO;
        unsigned int quantityPlanesOnShip = 0;
        map <string , pair <string, WarPlane *>> TableAirGroup;

        WarShip() {};
        ~WarShip() {};

        int CheckoutPlaces(WarShip *);

        int ModificatioPlane(string , WarShip *);

        int DamagePer1TimeUnitPlanes(WarShip *);

        int ModificationShip(int ,WarShip *);

        int ReturnInfoAboutShip(WarShip *);

        int ReturnInfoAboutPlanes(WarShip *);

        int MaxDistanceTransition(WarShip *);

        int DamagePer1TimeUnitShip(WarShip *);

        virtual int CheckoutPlacesForPlanes(std::ostream &strm) = 0;

        virtual void WriteSpecificInfo(std::ostream &strm) = 0;

        virtual void ModificationSpecificInfo(std::ostream &strm , unsigned int) = 0;

        virtual unsigned int QuantityOfPlaces(std::ostream &strm) = 0;

        friend ostream &operator <<(ostream &, const WarShip &);
    };
}
#endif //LABASOLO4_WARSHIP_H
