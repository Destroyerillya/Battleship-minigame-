//
// Created by Zver on 29.11.2017.
//

#ifndef LABASOLO4_CRUISER_H
#define LABASOLO4_CRUISER_H

#include "warship.h"

using namespace std;
using namespace warship;
using namespace mainhead;

namespace cruiser{

    class Cruiser : virtual public WarShip{
    public:
        string infoAboutCarryShip;

        Cruiser () {};
        Cruiser(unsigned int HP,unsigned int SPD,unsigned int SCF, vec::vector <Armament> givenWeapon, unsigned int QOCM,
                vec::vector <InfoAboutCap> givenHuman, string NAME_SHIP, string IACarryShip) {
            health = HP;
            speed = SPD;
            scopeFuel = SCF;
            quantityOfCrewMembers = QOCM;
            nameShip = NAME_SHIP;
            infoAboutCarryShip = IACarryShip;
            FIO = givenHuman;
            weapon = givenWeapon;
            type_ship = 1;
            givenHuman.clear();
            givenWeapon.clear();
        };
        ~Cruiser() {};

        virtual unsigned int QuantityOfPlaces(std::ostream &strm){};

        virtual int CheckoutPlacesForPlanes(std::ostream &strm){};

        virtual void ModificationSpecificInfo(std::ostream &strm , unsigned int VARIANT) override
        {
            string value;
            getline(cin, value, '\n');
            infoAboutCarryShip = value;
        }

        virtual void WriteSpecificInfo(std::ostream &strm) override
        {
            strm << "15.Information about carrying ship: " << endl << infoAboutCarryShip << endl;
        }
    };
}
#endif //LABASOLO4_CRUISER_H
