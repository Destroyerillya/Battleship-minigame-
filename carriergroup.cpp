//
// Created by Zver on 29.11.2017.
//
#include "carriergroup.h"
#include "fighter.h"
#include "bomber.h"

using namespace std;
using namespace carriergroup;
using namespace fighter;
using namespace bomber;

namespace carriergroup {

    void CarrierGroup::Copy(CarrierGroup MainGroup){
        countShips = MainGroup.countShips;
        countPlanes = MainGroup.countPlanes;
        auto Ship = MainGroup.TableCarryGroup.begin();
        while(Ship != MainGroup.TableCarryGroup.end()){
            TableCarryGroup.insert(pair<string, WarShip *>(Ship->first, Ship->second));
            Ship++;
        }
        auto CopyingShip = TableCarryGroup.begin();
        Ship = MainGroup.TableCarryGroup.begin();
        while(Ship != MainGroup.TableCarryGroup.end()){
            if(Ship->second->quantityPlanesOnShip != 0){
                auto Plane = Ship->second->TableAirGroup.begin();
                while(Plane != Ship->second->TableAirGroup.end()){
                    CopyingShip->second->TableAirGroup.insert(make_pair(Plane->first, pair <string, WarPlane *>(Plane->second.first, Plane->second.second)));
                    Plane++;
                }
            }
            Ship++;
            CopyingShip++;
        }
    }

    int CarrierGroup::Attack(CarrierGroup MainGroupAttack, CarrierGroup AttackGroup) {
        int i = 0;
        int k = 0;
        int x = 0;
        int y = 0;
        int m = 0;
        int RESULT = 0;
        int DMG_1 = 0;
        int DMG_2 = 0;
        int TOTAL_HP_TARGET_1_PLANE = 0;
        int TOTAL_HP_TARGET_2_SHIP = 0;
        int TOTAL_HP_TARGET_3_PLANE = 0;

        auto ShipAttack = AttackGroup.TableCarryGroup.begin();//корабль который с самолётами налётчиков
        auto PlaneAttack = ShipAttack->second->TableAirGroup.begin();//самолёт налётчик
        auto Ship = MainGroupAttack.TableCarryGroup.begin();//корабль
        auto Begin = MainGroupAttack.TableCarryGroup.begin();
        auto Ship_Aircraft = MainGroupAttack.TableCarryGroup.begin();//авианосцы
        auto Ship_Target = MainGroupAttack.TableCarryGroup.begin();//цель корабль
        auto Enemy_Plane_Target = ShipAttack->second->TableAirGroup.begin();//вражеский самолёт
        int b = 0;

        while(Begin != MainGroupAttack.TableCarryGroup.end()){
            if(Begin->second->type_ship != 1){
                b++;
            }
            Begin++;
        }

        while (RESULT == 0) {
            if (i == 0) {
                if(PlaneAttack == ShipAttack->second->TableAirGroup.end()){
                    PlaneAttack = ShipAttack->second->TableAirGroup.begin();
                }
                i = 1;
                auto PlaneAttackWeapon = PlaneAttack->second.second->weapon.begin();
                k = 0;
                while (k != PlaneAttack->second.second->countWeapons) {
                    DMG_1 += PlaneAttackWeapon->damagePerSec;
                    PlaneAttackWeapon++;
                    k++;
                }
                if (PlaneAttack->second.second->type_plane == 1) {
                    if (MainGroupAttack.countPlanes != 0 && (b != 0)) {
                        while ((Ship_Aircraft->second->type_ship == 1) && (Ship_Aircraft->second->quantityPlanesOnShip == 0)){
                            Ship_Aircraft++;
                        }
                        auto Plane_Target = Ship_Aircraft->second->TableAirGroup.begin();//цель самолёт
                        if (x == 0) {
                            TOTAL_HP_TARGET_1_PLANE = Plane_Target->second.second->health;
                            x++;
                        }
                        cout << "Your plane have " << TOTAL_HP_TARGET_1_PLANE << " health points." << endl;
                        TOTAL_HP_TARGET_1_PLANE -= DMG_1;
                        if (TOTAL_HP_TARGET_1_PLANE > 0) {
                            cout << "Enemy plane damaged " << DMG_1 << " and now your plain have "
                                 << TOTAL_HP_TARGET_1_PLANE << " health points." << endl;
                        } else {
                            cout << "Your plane was destroyed." << endl;
                            Ship_Aircraft->second->TableAirGroup.erase(Plane_Target->first);
                            Ship_Aircraft->second->quantityPlanesOnShip--;
                            MainGroupAttack.countPlanes--;
                            if(MainGroupAttack.countPlanes != 0) {
                                if (Ship_Aircraft->second->quantityPlanesOnShip == 0) {
                                    Ship_Aircraft = MainGroupAttack.TableCarryGroup.begin();
                                    if (b != 0) {
                                        while ((Ship_Aircraft->second->type_ship == 1) &&
                                               (Ship_Aircraft->second->quantityPlanesOnShip == 0)) {
                                            Ship_Aircraft++;
                                        }
                                        Plane_Target = Ship_Aircraft->second->TableAirGroup.begin();
                                    }
                                } else {
                                    Plane_Target = Ship_Aircraft->second->TableAirGroup.begin();
                                }
                            }
                        }
                        x--;
                    } else {
                        cout << "Fighter cannot attack." << endl;
                    }
                }
                else {
                    if (m == 0) {
                        TOTAL_HP_TARGET_2_SHIP = Ship_Target->second->health;
                        m = 1;
                    }
                    cout << "Your ship have " << TOTAL_HP_TARGET_2_SHIP << " health points" << endl;
                    TOTAL_HP_TARGET_2_SHIP -= DMG_1;
                    if (TOTAL_HP_TARGET_2_SHIP > 0) {
                        cout << "Enemy plane damaged " << DMG_1 << " and now your ship have " << TOTAL_HP_TARGET_2_SHIP << " health points" << endl;
                    } else {
                        cout << "Your ship was destroyed" << endl;
                        MainGroupAttack.countShips--;
                        if(Ship_Target->second->type_ship != 1){
                            b--;
                            if(b != 0) {
                                Ship_Aircraft = MainGroupAttack.TableCarryGroup.begin();
                                while ((Ship_Aircraft->second->type_ship == 1) && (Ship_Aircraft->second->quantityPlanesOnShip == 0)){
                                    Ship_Aircraft++;
                                }
                            }
                        }
                        MainGroupAttack.TableCarryGroup.erase(Ship_Target->first);
                        if(MainGroupAttack.countShips != 0) {
                            Ship = MainGroupAttack.TableCarryGroup.begin();
                            Ship_Target = MainGroupAttack.TableCarryGroup.begin();
                        }
                        m = 0;
                    }
                }
                if(ShipAttack->second->quantityPlanesOnShip != 1) {
                    PlaneAttack++;
                }
                if(MainGroupAttack.countShips == 0){
                    RESULT = -1;
                }
                DMG_1 = 0;
            }
            else {
                i = 0;
                if(Ship == MainGroupAttack.TableCarryGroup.end()){
                    Ship = MainGroupAttack.TableCarryGroup.begin();
                }
                auto ShipWeapon = Ship->second->weapon.begin();
                DMG_2 += ShipWeapon->damagePerSec;
                if (Ship->second->quantityPlanesOnShip != 0) {
                    auto ShipPlanesWeapons = Ship->second->TableAirGroup.begin();
                    while (ShipPlanesWeapons != Ship->second->TableAirGroup.end()) {
                        if (ShipPlanesWeapons->second.second->type_plane == 1) {
                            auto ShipPlaneWeapon = ShipPlanesWeapons->second.second->weapon.begin();
                            k = 0;
                            while (k != ShipPlanesWeapons->second.second->countWeapons) {
                                DMG_2 += ShipPlaneWeapon->damagePerSec;
                                ShipPlaneWeapon++;
                                k++;
                            }
                        }
                        ShipPlanesWeapons++;
                    }
                }
                if (y == 0) {
                    TOTAL_HP_TARGET_3_PLANE = Enemy_Plane_Target->second.second->health;
                    y++;
                }
                cout << "Enemy plane have " << TOTAL_HP_TARGET_3_PLANE << " health points" << endl;
                TOTAL_HP_TARGET_3_PLANE -= DMG_2;
                if (TOTAL_HP_TARGET_3_PLANE > 0) {
                    cout << "Your planes and ship damaged " << DMG_2 << " and now enemy plain have "
                         << TOTAL_HP_TARGET_3_PLANE << " health points" << endl;
                } else {
                    cout << "Enemy plane was destroyed" << endl;
                    ShipAttack->second->quantityPlanesOnShip--;
                    ShipAttack->second->TableAirGroup.erase(Enemy_Plane_Target->first);
                    if(ShipAttack->second->quantityPlanesOnShip != 0) {
                        PlaneAttack = ShipAttack->second->TableAirGroup.begin();
                        Enemy_Plane_Target = ShipAttack->second->TableAirGroup.begin();
                    }
                    y--;
                }
                DMG_2 = 0;
                if(MainGroupAttack.countShips != 1){
                    Ship++;
                }
                if(ShipAttack->second->quantityPlanesOnShip == 0){
                    RESULT = 1;
                }
            }
        }
        if (RESULT == 1) {
            return 1;
        }
        else {
            return -1;
        }
    }

    int CarrierGroup::InputingAttackGroup(unsigned int PLANES,string CALLSIGN) {
        unsigned int TYPE_PLANE;
        string CALLSIGN_PLANE;
        unsigned int HP;
        unsigned int SPD;
        unsigned int SCF;
        unsigned int TYPE_ARMAMENT;
        unsigned int QUANTITY_WEAPONS;
        string NAME_ARMA;
        string NAME_AMMO;
        unsigned int AMMO;
        unsigned int DMG;
        unsigned int ROF;
        int i = 0;

        Armament GIVEN_WEAPON;
        vec::vector <Armament> WEAPON;

        auto SHIP = TableCarryGroup.begin();
        while(PLANES != 0){
            i = 1;
            TYPE_PLANE = rand() % 2 + 1;
            HP = rand() % 100 + 1;
            SCF = rand() % 2 + 1;
            SPD = rand () % 2 + 1;

            QUANTITY_WEAPONS = 1 + rand() % ( 3 - 1 );
            TYPE_ARMAMENT = rand() % 2 + 1;
            GIVEN_WEAPON.type = Armament::getTypeByNum(TYPE_ARMAMENT);
            NAME_ARMA = rand() % 2 + 1;
            GIVEN_WEAPON.nameOfArmament = NAME_ARMA;
            NAME_AMMO = rand() % 2 + 1;
            GIVEN_WEAPON.nameOfAmmunition = NAME_AMMO;
            AMMO = 1;
            GIVEN_WEAPON.ammunition = AMMO;
            DMG = rand() % 50 + 1;
            GIVEN_WEAPON.damagePerSec = DMG;
            ROF = 1;
            GIVEN_WEAPON.rateOfFire = ROF;
            WEAPON.push_back(GIVEN_WEAPON);
            CALLSIGN_PLANE = rand() % 10000 + 1;
            if(TYPE_PLANE == 1) {
                (*SHIP).second->TableAirGroup.insert(make_pair(CALLSIGN_PLANE, pair < string, WarPlane *>(CALLSIGN, new Fighter (HP,SPD,SCF,WEAPON))));
                SHIP->second->quantityPlanesOnShip++;
            }
            else{
                (*SHIP).second->TableAirGroup.insert(make_pair(CALLSIGN_PLANE, pair < string, WarPlane *>(CALLSIGN, new Bomber (HP,SPD,SCF,WEAPON))));
                SHIP->second->quantityPlanesOnShip++;
            }
            auto PLANE = SHIP->second->TableAirGroup.find(CALLSIGN_PLANE);
            while(i != QUANTITY_WEAPONS){
                TYPE_ARMAMENT = rand() % 2 + 1;
                GIVEN_WEAPON.type = Armament::getTypeByNum(TYPE_ARMAMENT);
                NAME_ARMA = rand() % 2 + 1;
                GIVEN_WEAPON.nameOfArmament = NAME_ARMA;
                NAME_AMMO = rand() % 2 + 1;
                GIVEN_WEAPON.nameOfAmmunition = NAME_AMMO;
                AMMO = 1;
                GIVEN_WEAPON.ammunition = AMMO;
                DMG = rand() % 50 + 1;
                GIVEN_WEAPON.damagePerSec = DMG;
                ROF = 1;
                GIVEN_WEAPON.rateOfFire = ROF;
                WEAPON.push_back(GIVEN_WEAPON);
                PLANE->second.second->weapon.push_back(GIVEN_WEAPON);
                i++;
                PLANE->second.second->countWeapons++;
            }
            WEAPON.clear();
            PLANES--;
        }
        return 1;
    }

    int CarrierGroup::ReturnQuantityOfShipsOfACertainType(unsigned int TYPE_SHIP){
        unsigned int count = 0;
        auto MapViewShips = TableCarryGroup.begin();
        for(MapViewShips; MapViewShips != TableCarryGroup.end(); MapViewShips++)
        {
           if((*MapViewShips).second->type_ship == TYPE_SHIP){
               count++;
           }
        }
        return count++;
    }

    int CarrierGroup::ViewShips(){
        auto MapViewShips = TableCarryGroup.begin();
        for(MapViewShips; MapViewShips != TableCarryGroup.end(); MapViewShips++)
        {
            cout << MapViewShips->first << " : " << MapViewShips->second << endl;
        }
    }

    int CarrierGroup::DeleteShipOfGroup(string CALLSIGN) {
        auto MapDeleting = TableCarryGroup.begin();
        MapDeleting = TableCarryGroup.find(CALLSIGN);
        TableCarryGroup.erase(CALLSIGN);
    }

    int CarrierGroup::DeletePlaneOfGroup(string CALLSIGN, string CALLSIGN_PLANE){
        auto MapView = TableCarryGroup.find(CALLSIGN);
        MapView->second->TableAirGroup.erase(CALLSIGN_PLANE);
        MapView->second->quantityPlanesOnShip--;
    }

    int CarrierGroup::AddPlaneToGroup(string CALLSIGN, WarPlane* plane,string CALLSIGN_PLANE) {
        auto search = TableCarryGroup.find(CALLSIGN);
        (*search).second->TableAirGroup.insert(make_pair(CALLSIGN_PLANE, pair < string, WarPlane *>(CALLSIGN, plane)));
        (*search).second->quantityPlanesOnShip++;
        return 1;
    }

    int CarrierGroup::InputInfo(vec::vector<InfoAboutCap> givenHuman, unsigned int DISBETPOINT, string DESTINATION, string POD) {
        pointOfDeparture = POD;
        destination = DESTINATION;
        distanceBetweenPoints = DISBETPOINT;
        MAINCAPFIO = givenHuman;
        givenHuman.clear();
        return 1;
    }

    int CarrierGroup::SearchAircraftInGroup(string CALLSIGN) {
        auto search = TableCarryGroup.find(CALLSIGN);
        if(search == TableCarryGroup.end() || (*search).second->type_ship == 1) {
            return -1;
        }
        else {
            return 1;
        }
    }

    int CarrierGroup::SearchCallsignsInGroup(string CALLSIGN) {
        auto search = TableCarryGroup.find(CALLSIGN);
        if(search == TableCarryGroup.end()) {
            auto search = TableCarryGroup.begin();
            while(search != TableCarryGroup.end()){
                auto searchPlane = (*search).second->TableAirGroup.find(CALLSIGN);
                if(searchPlane != (*search).second->TableAirGroup.end()) {
                    return -1;
                }
                else {
                    search++;
                }
            }
            return 1;
        }
        else {
            return -1;
        }
    }

    int CarrierGroup::AirplaneTransfer(string CALLSIGN, string CALLSIGN_PLANE, string CALLSIGN_TRANSFER) {
        unsigned int HP;
        unsigned int SPD;
        unsigned int SCF;
        unsigned int TYPE_ARMAMENT;
        string NAME_ARMA;
        string NAME_AMMO;
        unsigned int AMMO;
        unsigned int DMG;
        unsigned int ROF;
        unsigned int NUMBER_OF_PLANE;
        int COUNT = 0;

        Armament WEAPONING;
        vec::vector <Armament> WEAPON;

        auto SHIP = TableCarryGroup.find(CALLSIGN);
        auto SHIP_TRANSFER = TableCarryGroup.find(CALLSIGN_TRANSFER);
        auto PLANE = SHIP->second->TableAirGroup.find(CALLSIGN_PLANE);
        unsigned int i = (*SHIP_TRANSFER).second->QuantityOfPlaces(cout);
        HP = PLANE->second.second->health;
        SPD = PLANE->second.second->speed;
        SCF = PLANE->second.second->scopeFuel;
        auto ITPlaneWeapon = PLANE->second.second->weapon.begin();
        WEAPONING.damagePerSec = ITPlaneWeapon->damagePerSec;
        WEAPONING.type = ITPlaneWeapon->type;
        WEAPONING.rateOfFire = ITPlaneWeapon->rateOfFire;
        WEAPONING.nameOfAmmunition = ITPlaneWeapon->nameOfAmmunition;
        WEAPONING.nameOfArmament = ITPlaneWeapon->nameOfArmament;
        WEAPONING.ammunition = ITPlaneWeapon->ammunition;
        WEAPON.push_back(WEAPONING);
        if((*SHIP_TRANSFER).second->quantityPlanesOnShip < i ) {
            if(PLANE->second.second->type_plane = 1){
                (*SHIP_TRANSFER).second->TableAirGroup.insert(make_pair(CALLSIGN_PLANE,pair < string, WarPlane *>
                        (CALLSIGN_TRANSFER, new Fighter (HP, SPD, SCF, WEAPON))));
            }
            else {
                (*SHIP_TRANSFER).second->TableAirGroup.insert(make_pair(CALLSIGN_PLANE,pair < string, WarPlane *>
                        (CALLSIGN_TRANSFER,new Bomber (HP, SPD, SCF, WEAPON))));
            }
            auto PLANE_TRANSFER = SHIP_TRANSFER->second->TableAirGroup.find(CALLSIGN_PLANE);
            auto ITPlaneWeapon = PLANE->second.second->weapon.begin();
            ITPlaneWeapon++;
            while(PLANE_TRANSFER->second.second->countWeapons != PLANE->second.second->countWeapons){
                WEAPONING.damagePerSec = ITPlaneWeapon->damagePerSec;
                WEAPONING.type = ITPlaneWeapon->type;
                WEAPONING.rateOfFire = ITPlaneWeapon->rateOfFire;
                WEAPONING.nameOfAmmunition = ITPlaneWeapon->nameOfAmmunition;
                WEAPONING.nameOfArmament = ITPlaneWeapon->nameOfArmament;
                WEAPONING.ammunition = ITPlaneWeapon->ammunition;
                ITPlaneWeapon++;
                PLANE_TRANSFER->second.second->weapon.push_back(WEAPONING);
                PLANE_TRANSFER->second.second->countWeapons++;
            }
            SHIP_TRANSFER->second->quantityPlanesOnShip++;
            SHIP->second->TableAirGroup.erase(CALLSIGN_PLANE);
            SHIP->second->quantityPlanesOnShip--;
            WEAPON.clear();
            return 1;
        }
        else
            return -1;
    }

}