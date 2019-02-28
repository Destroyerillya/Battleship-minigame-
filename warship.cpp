//
// Created by Zver on 28.11.2017.
//
#include "warship.h"
#include "cruiser.h"

using namespace std;
using namespace warship;
using namespace mainhead;
using namespace cruiser;


namespace warship{

    int WarShip::CheckoutPlaces (WarShip *SHIP) {
        if(SHIP->CheckoutPlacesForPlanes(cout) == -1)
            return -1;
        else
            return 1;
    }

    int WarShip::DamagePer1TimeUnitPlanes(WarShip *SHIP) {
        int damage = 0;
        int i = 0;
        auto ITPlain = SHIP->TableAirGroup.begin();
        while(ITPlain != SHIP->TableAirGroup.end()){
            auto ITWeaponPLANE = ITPlain->second.second->weapon.begin();
            i = 0;
            while(i < ITPlain->second.second->countWeapons){
                damage += ITWeaponPLANE->damagePerSec;
                ITWeaponPLANE++;
                i++;
            }
            ITPlain++;
        }
        return damage*60;
    }

    int WarShip::ModificatioPlane(string CALLSIGN_PLANE, WarShip *SHIP) {//fix all weapons modification
        Armament newweapon;
        unsigned int key;
        unsigned int value;
        string VALUE;
        auto ITplain = SHIP->TableAirGroup.find(CALLSIGN_PLANE);
        auto ITweaponPLANE = ITplain->second.second->weapon.begin();
        cout <<ITplain->first << " " <<  ITplain->second.first << " " << ITplain->second.second << " " << endl; // вывод всей информации про самолёт
        cout << "Your plane input variant (1-Health,2-Speed,3-ScopeFuel,4-Type Of Weapon,"
                "5-Name of Ammunition,6-Name Of Armament, 7-Rate Of Fire,8-DMG per sec,9-Ammunition,10-Add new weapon :" << endl;
        while (!getNum(key) || key > 10) {
            cout << "Incorrect input variant. Try again:";
        }
        cout << "Input value:" <<endl;
        if (key == 1) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            ITplain->second.second->health = value;
        }
        if (key  == 2) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            ITplain->second.second->speed = value;
        }
        if (key  == 3) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            ITplain->second.second->scopeFuel = value;
        }
        if (key == 4) {
            while (!getNum(value) || value > 2) {
                cout << "Incorrect input variant. Try again:";
            }
            ITweaponPLANE->type = ITweaponPLANE->getTypeByNum(value);
        }
        if (key == 5) {
            getline(cin,VALUE,'\n');
            ITweaponPLANE->nameOfAmmunition = VALUE;
        }
        if (key == 6) {
            getline(cin,VALUE,'\n');
            ITweaponPLANE->nameOfArmament = VALUE;
        }
        if (key == 7) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            ITweaponPLANE->rateOfFire = value;
        }
        if (key == 8) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            ITweaponPLANE->damagePerSec = value;
        }
        if (key == 9) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            ITweaponPLANE->ammunition = value;
        }
        if (key == 10) {
            if(ITplain->second.second->countWeapons < 3) {
                cout << "Input type of armament (1-Light and 2-Heavy):" << endl;
                while (!getNum(value) || value > 2) {
                    cout << "Incorrect input variant. Try again:";
                }
                newweapon.type = newweapon.getTypeByNum(value);

                cout << "Input name of armament:" << endl;
                getline(cin, VALUE, '\n');
                newweapon.nameOfArmament = VALUE;

                cout << "Input name of ammunition:" << endl;
                getline(cin, VALUE, '\n');
                newweapon.nameOfAmmunition = VALUE;

                cout << "Input quantity of ammunition:" << endl;
                while (!getNum(value)) {
                    cout << "Incorrect input variant. Try again:";
                }
                newweapon.ammunition = value;

                cout << "Input damage per second:" << endl;
                while (!getNum(value)) {
                    cout << "Incorrect input variant. Try again:";
                }
                newweapon.damagePerSec = value;
                cout << "Input rate of fire:" << endl;
                while (!getNum(value)) {
                    cout << "Incorrect input variant. Try again:";
                }
                newweapon.rateOfFire = value;
                ITplain->second.second->weapon.push_back(newweapon);
                ITplain->second.second->countWeapons++;
            }
            else{
                cout <<"Sry plane can have only 3 weapons." << endl;
            }
        }
        return 1;
    }

    int WarShip::ReturnInfoAboutPlanes(WarShip *SHIP) {
        auto ITplanesShip = TableAirGroup.begin();
        if(SHIP->quantityPlanesOnShip != 0) {
            while (ITplanesShip != TableAirGroup.end()) {
                cout << ITplanesShip->first << " : " << ITplanesShip->second.first << " : " << ITplanesShip->second.second << endl;
                ITplanesShip++;
            }
            return 1;
        }
        else{
            return -1;
        }
    }

    int WarShip::DamagePer1TimeUnitShip(WarShip *SHIP) {
        auto ITweaponSHIP = SHIP->weapon.begin();
        return 60*ITweaponSHIP->damagePerSec;
    }

    int WarShip::MaxDistanceTransition(WarShip *SHIP) {
        return SHIP->speed * SHIP->scopeFuel;
    }

    int WarShip::ModificationShip(int VARIANT,WarShip *SHIP) {
        unsigned int value;
        string VALUE;
        auto ITweaponSHIP = weapon.begin();
        auto ITcapSHIP = FIO.begin();
        cout << "Input value:" << endl;
        if (VARIANT == 1) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            SHIP->health = value;
        }
        if (VARIANT == 2) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            SHIP->speed = value;
        }
        if (VARIANT == 3) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            SHIP->scopeFuel = value;
        }
        if (VARIANT == 4) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            SHIP->quantityOfCrewMembers = value;
        }
        if (VARIANT == 5) {
            getline(cin, VALUE, '\n');
            SHIP->nameShip = VALUE;
        }
        if (VARIANT == 6) {
            while (!getNum(value) || value > 2) {
                cout << "Incorrect input variant. Try again:";
            }
            ITweaponSHIP->type = ITweaponSHIP->getTypeByNum(value);
        }
        if (VARIANT == 7) {
            getline(cin, VALUE, '\n');
            ITweaponSHIP->nameOfAmmunition = VALUE;
        }
        if (VARIANT == 8) {
            getline(cin, VALUE, '\n');
            ITweaponSHIP->nameOfArmament = VALUE;
        }
        if (VARIANT == 9) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            ITweaponSHIP->rateOfFire = value;
        }
        if (VARIANT == 10) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            ITweaponSHIP->damagePerSec = value;
        }
        if (VARIANT == 11) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            ITweaponSHIP->ammunition = value;
        }
        if (VARIANT == 12) {
            getline(cin, VALUE, '\n');
            ITcapSHIP->NameOurCapitan = VALUE;
        }
        if (VARIANT == 13) {
            cout << "Input rank(Captain3rdRank = 1,Captain2rdRank = 2,Captain1rdRank = 3) of your cap:" << endl;
            while (!getNum(value) || value > 3) {
                cout << "Incorrect input variant. Try again:";
            }
            ITcapSHIP->capitansRank = ITcapSHIP->getRankByNum(value);
        }
        if (VARIANT == 14) {
            while (!getNum(value)) {
                cout << "Incorrect input variant. Try again:";
            }
            ITcapSHIP->experience = value;
        }
        if (VARIANT == 15 || VARIANT == 16){
            SHIP->ModificationSpecificInfo(cout,VARIANT);
        }
        return 1;
    }

    int WarShip::ReturnInfoAboutShip (WarShip *SHIP){
        cout << "1.Health:" << SHIP->health << endl;
        cout << "2.Speed:" << SHIP->speed << endl;
        cout << "3.Scope Fuel:" << SHIP->scopeFuel << endl;
        cout << "4.Quantity of crew members:" << SHIP->quantityOfCrewMembers << endl;
        cout << "5.Name of your ship:" << SHIP->nameShip << endl;
        auto ITweaponSHIP = weapon.begin();
        cout << "6.Type of weapon on ship(Light - 1, Heavy - 2):" <<endl;
        cout << ITweaponSHIP->type << endl;
        cout << "7.Name of ammunition :" <<endl;
        cout << ITweaponSHIP->nameOfAmmunition << endl;
        cout << "8.Name of armament:" <<endl;
        cout << ITweaponSHIP->nameOfArmament << endl;//-вылет
        cout << "9.Rate of fire:" <<endl;
        cout << ITweaponSHIP->rateOfFire << endl;
        cout << "10.DMG per sec:" <<endl;
        cout << ITweaponSHIP->damagePerSec<< endl;
        cout << "11.Ammunition :" <<endl;
        cout << ITweaponSHIP->ammunition << endl;
        auto ITcapSHIP = FIO.begin();
        cout << "12.Name of ship-cap:" <<endl;
        cout << ITcapSHIP->NameOurCapitan << endl;
        cout << "13.Capitans rank:" <<endl;
        cout << ITcapSHIP->capitansRank << endl;
        cout << "14.Experience:" <<endl;
        cout << ITcapSHIP->experience << endl;
        SHIP->WriteSpecificInfo(cout);
    }
}