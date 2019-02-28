//
// Created by Zver on 28.11.2017.
//

#ifndef LABASOLO4_AIRCRAFTCARRIER_H
#define LABASOLO4_AIRCRAFTCARRIER_H

#include "warship.h"
#include "warplane.h"

using namespace std;
using namespace warship;
using namespace warplane;
using namespace mainhead;

namespace aircraftcarrier{

    class AircraftCarrier : virtual public WarShip{
    public:
        unsigned int quantityPlacesForPlanes = 0;

        AircraftCarrier() {};
        AircraftCarrier(unsigned int HP,unsigned int SPD,unsigned int SCF, vec::vector <Armament> givenWeapon, unsigned int QOCM,
                        vec::vector <InfoAboutCap> givenHuman, string NAME_SHIP, unsigned int QPFP) {
            health = HP;
            speed = SPD;
            scopeFuel = SCF;
            quantityOfCrewMembers = QOCM;
            quantityPlacesForPlanes = QPFP;
            nameShip = NAME_SHIP;
            FIO = givenHuman;
            type_ship = 2;
            weapon = givenWeapon;
            givenHuman.clear();
            givenWeapon.clear();
        };
        ~AircraftCarrier() {};

        virtual unsigned int QuantityOfPlaces(std::ostream &strm){
            return quantityPlacesForPlanes;
        };

        virtual int CheckoutPlacesForPlanes(std::ostream &strm)  override
        {
            if(quantityPlanesOnShip == quantityPlacesForPlanes){
                return -1;
            }
            else
                return 1;
        }

        virtual void ModificationSpecificInfo(std::ostream &strm , unsigned int VARIANT) override
        {
            unsigned int value;
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            quantityPlacesForPlanes = value;
        }

        virtual void WriteSpecificInfo(std::ostream &strm) override
        {
            strm << "15.Information about quantity places for planes: "<< endl << quantityPlacesForPlanes << endl;
        }
    };
}

#endif //LABASOLO4_AIRCRAFTCARRIER_H
