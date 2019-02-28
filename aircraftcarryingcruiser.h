//
// Created by Zver on 29.11.2017.
//

#ifndef LABASOLO4_AIRCRAFTCARRYINGCRUISER_H
#define LABASOLO4_AIRCRAFTCARRYINGCRUISER_H

#include "cruiser.h"
#include "aircraftcarrier.h"

using namespace cruiser;
using namespace aircraftcarrier;

namespace aircraftcarryingcruiser {
    class AircraftCarryingCruiser : public Cruiser, public AircraftCarrier {
    public:
        AircraftCarryingCruiser(){};
        AircraftCarryingCruiser(unsigned int HP,unsigned int SPD,unsigned int SCF, vec::vector <Armament> givenWeapon, unsigned int QOCM,
                                vec::vector <InfoAboutCap> givenHuman, string NAME_SHIP, string IACarryShip,unsigned int QPFP){
            health = HP;
            speed = SPD;
            scopeFuel = SCF;
            quantityOfCrewMembers = QOCM;
            nameShip = NAME_SHIP;
            infoAboutCarryShip = IACarryShip;
            quantityPlacesForPlanes = QPFP;
            type_ship = 3;
            FIO = givenHuman;
            weapon = givenWeapon;
            givenHuman.clear();
            givenWeapon.clear();
        };
        ~AircraftCarryingCruiser(){};

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
            if(VARIANT == 15){
                getline(cin, infoAboutCarryShip , '\n');
            }
            else {
                while (!getNum(quantityPlacesForPlanes)) {
                    cout << "Incorrect input variant. Try again:";
                }
            }
        }

        virtual void WriteSpecificInfo(std::ostream &strm) override
        {
            strm << "15.Information about carrying ship: " << endl << infoAboutCarryShip << endl;
            strm << "16.Information about Information about quantity places for planes: "<< endl << quantityPlacesForPlanes << endl;
        }
    };
}
#endif //LABASOLO4_AIRCRAFTCARRYINGCRUISER_H
