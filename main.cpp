#include <iostream>

#include "cruiser.h"
#include "aircraftcarrier.h"
#include "aircraftcarryingcruiser.h"
#include "carriergroup.h"
#include "fighter.h"
#include "bomber.h"

using namespace mainhead;
using namespace std;
using namespace cruiser;
using namespace carriergroup;
using namespace combatunit;
using namespace aircraftcarrier;
using namespace aircraftcarryingcruiser;
using namespace fighter;
using namespace bomber;


int main() {

    int variant;
    unsigned int HP;
    unsigned int SPD;
    unsigned int SCF;
    unsigned int TYPE_ARMAMENT;
    string NAME_ARMA;
    string NAME_AMMO;
    unsigned int AMMO;
    unsigned int DMG;
    unsigned int ROF;
    string NAME_SHIP;
    unsigned int QOCM;
    string IACarryShip;
    unsigned int QPFP;
    string NOC;
    unsigned int RANK;
    unsigned int EXP;
    string CALLSIGN;
    string CALLSIGN_PLANE;
    string CALLSIGN_TRANSFER;
    string POD;
    string DESTINATION;
    unsigned int DISBETPOINT;
    string MAIN_NOC;
    unsigned int MAIN_RANK;
    unsigned int MAIN_EXP;
    unsigned int TYPE_SHIP;
    unsigned int PLANES;
    int COUNT = 0;
    int i = 0;

    InfoAboutCap human;
    vec::vector <InfoAboutCap> givenHuman;

    InfoAboutCap MAIN_human;
    vec::vector <InfoAboutCap> MAIN_givenHuman;

    Armament weaponing;
    vec::vector <Armament> givenWeapon;

    CarrierGroup MainGroup;

    do {
        cout << "Enter the menu number:" << endl;
        cout << "1.Create new carrier group." << endl;
        cout << "2.Virtual fight." << endl;
        cout << "3.Exit." << endl;
        cin.clear();
        while (!getNum(variant) || variant > 4) {
            cout << "Incorrect input variant. Try again:";
        }
        switch (variant) {
            case 1: {
                do {
                    cout << "Enter the menu number:" << endl;
                    cout << "1.Create new carrier group." << endl;
                    cout << "2.Use old carrier group." << endl;
                    cin.clear();
                    while (!getNum(variant) || variant > 2) {
                        cout << "Incorrect input variant. Try again:";
                    }
                    switch (variant) {
                        case 1: {
                            cout << "Input name of warlord:" << endl;
                            getline(cin, MAIN_NOC, '\n');
                            MAIN_human.NameOurCapitan = MAIN_NOC;
                            cout << "Input experience of your warlord:" << endl;
                            while (!getNum(MAIN_EXP)) {
                                cout << "Incorrect input variant. Try again:";
                            }
                            MAIN_human.experience = MAIN_EXP;
                            cout << "Input rank(ViceAdmiral = 5, Admiral = 6) of your warlord:" << endl;
                            while (!getNum(MAIN_RANK) || MAIN_RANK > 6 || MAIN_RANK < 5) {
                                cout << "Incorrect input variant. Try again:";
                            }
                            MAIN_human.capitansRank = InfoAboutCap::getRankByNum(MAIN_RANK);
                            MAIN_givenHuman.push_back(MAIN_human);
                            cout << "Input point of departure:" << endl;
                            getline(cin, POD, '\n');
                            cout << "Input point of destination:" << endl;
                            getline(cin, DESTINATION, '\n');
                            cout << "Input distance between two points:" << endl;
                            while (!getNum(DISBETPOINT)) {
                                cout << "Incorrect input variant. Try again:";
                            }
                            i = 1;
                            MainGroup.InputInfo(MAIN_givenHuman, DISBETPOINT, DESTINATION, POD);
                            MAIN_givenHuman.clear();
                            break;
                        }
                        case 2: {
                            if(i == 0){
                                cout << "Sry but group is not create" << endl;
                            }
                            break;
                        }
                        default:break;
                    }
                }while (i == 0);
                do {
                    cout << "Enter the menu number:" << endl;
                    cout << "1.Add ship to group." << endl;
                    cout << "2.Add plane to group." << endl;
                    cout << "3.Delete ship of group." << endl;
                    cout << "4.Delete plane of group." << endl;
                    cout << "5.Return quantity one type of ship and quantity of all ships in group." << endl;
                    cout << "6.Choose a ship over will we perform actions." << endl;
                    cout << "7.Viewer ships." << endl;
                    cout << "8.Transfer plane." << endl;
                    cout << "9.Back." << endl;
                    cin.clear();
                    while (!getNum(variant) || variant > 9) {
                        cout << "Incorrect input variant. Try again:" << endl;
                    }
                    switch (variant) {
                        case 1: {
                            do {
                                cout << "Enter the menu number:" << endl;
                                cout << "1.Add cruiser to group." << endl;
                                cout << "2.Add aircraftcarrier to group." << endl;
                                cout << "3.Add aircraftcarryingcruiser of group." << endl;
                                cout << "4.Back." << endl;
                                cin.clear();
                                while (!getNum(variant) || variant > 4) {
                                    cout << "Incorrect input variant. Try again:";
                                }
                                switch (variant) {
                                    case 1: {
                                        cout << "Input health:" << endl;
                                        while (!getNum(HP)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        cout << "Input speed:" << endl;
                                        while (!getNum(SPD)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        cout << "Input scope fuel:" << endl;
                                        while (!getNum(SCF)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        cout << "Input type of armament (1-Light or 2-Heavy):" << endl;
                                        while (!getNum(TYPE_ARMAMENT)|| TYPE_ARMAMENT > 2) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        weaponing.type = Armament::getTypeByNum(TYPE_ARMAMENT);
                                        cout << "Input name of armament:" << endl;
                                        getline(cin, NAME_ARMA, '\n');
                                        weaponing.nameOfArmament = NAME_ARMA;
                                        cout << "Input name of ammunition:" << endl;
                                        getline(cin, NAME_AMMO, '\n');
                                        weaponing.nameOfAmmunition = NAME_AMMO;
                                        cout << "Input quantity of ammunition:" << endl;
                                        while (!getNum(AMMO)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        weaponing.ammunition = AMMO;
                                        cout << "Input damage per second:" << endl;
                                        while (!getNum(DMG)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        weaponing.damagePerSec = DMG;
                                        cout << "Input rate of fire:" << endl;
                                        while (!getNum(ROF)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        weaponing.rateOfFire = ROF;
                                        cout << "Input quantity of crew members:" << endl;
                                        while (!getNum(QOCM)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        cout << "Input name of your ship:" << endl;
                                        getline(cin, NAME_SHIP, '\n');
                                        cout << "Input name of capitan:" << endl;
                                        getline(cin, NOC, '\n');
                                        human.NameOurCapitan = NOC;
                                        cout << "Input experience of your cap:" << endl;
                                        while (!getNum(EXP)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        human.experience = EXP;
                                        cout << "Input rank(Captain3rdRank = 1,Captain2rdRank = 2,Captain1rdRank = 3) of your cap:" << endl;
                                        while (!getNum(RANK)|| RANK > 3) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        human.capitansRank = InfoAboutCap::getRankByNum(RANK);
                                        cout << "Input callsign of your ship:" << endl;
                                        getline(cin, CALLSIGN, '\n');
                                        while (MainGroup.SearchCallsignsInGroup(CALLSIGN) == -1 || CALLSIGN.empty()) {
                                            CALLSIGN.clear();
                                            cout << "Incorrect input variant or callsign is used. Try again:";
                                            getline(cin, CALLSIGN, '\n');
                                        }
                                        cout << "Input information about carrying ship:" << endl;
                                        getline(cin, IACarryShip, '\n');
                                        givenHuman.push_back(human);
                                        givenWeapon.push_back(weaponing);
                                        MainGroup.TableCarryGroup.insert(pair<string, WarShip *>(CALLSIGN, new Cruiser
                                                (HP,SPD,SCF,givenWeapon,QOCM,givenHuman, NAME_SHIP,IACarryShip)));
                                        MainGroup.countShips++;
                                        givenWeapon.clear();
                                        givenHuman.clear();
                                        break;
                                    }
                                    case 2: {
                                        cout << "Input health:" << endl;
                                        while (!getNum(HP)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        cout << "Input speed:" << endl;
                                        while (!getNum(SPD)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        cout << "Input scope fuel:" << endl;
                                        while (!getNum(SCF)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        cout << "Input type of armament (Only 1-Light):" << endl;
                                        while (!getNum(TYPE_ARMAMENT)|| TYPE_ARMAMENT > 1) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        weaponing.type = Armament::getTypeByNum(TYPE_ARMAMENT);
                                        cout << "Input name of armament:" << endl;
                                        getline(cin, NAME_ARMA, '\n');
                                        weaponing.nameOfArmament = NAME_ARMA;
                                        cout << "Input name of ammunition:" << endl;
                                        getline(cin, NAME_AMMO, '\n');
                                        weaponing.nameOfAmmunition = NAME_AMMO;
                                        cout << "Input quantity of ammunition:" << endl;
                                        while (!getNum(AMMO)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        weaponing.ammunition = AMMO;
                                        cout << "Input damage per second:" << endl;
                                        while (!getNum(DMG)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        weaponing.damagePerSec = DMG;
                                        cout << "Input rate of fire:" << endl;
                                        while (!getNum(ROF)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        weaponing.rateOfFire = ROF;
                                        cout << "Input quantity of crew members:" << endl;
                                        while (!getNum(QOCM)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        cout << "Input name of your ship:" << endl;
                                        getline(cin, NAME_SHIP, '\n');
                                        cout << "Input name of capitan:" << endl;
                                        getline(cin, NOC, '\n');
                                        human.NameOurCapitan = NOC;
                                        cout << "Input experience of your cap:" << endl;
                                        while (!getNum(EXP)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        human.experience = EXP;
                                        cout << "Input rank(Captain1rdRank = 3,RearAdmiral = 4) of your cap:" << endl;
                                        while (!getNum(RANK)|| RANK > 4 || RANK < 3) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        human.capitansRank = InfoAboutCap::getRankByNum(RANK);
                                        cout << "Input callsign of your ship:" << endl;
                                        getline(cin, CALLSIGN, '\n');
                                        while (MainGroup.SearchCallsignsInGroup(CALLSIGN) == -1 || CALLSIGN.empty()) {
                                            CALLSIGN.clear();
                                            cout << "Incorrect input variant or callsign is used. Try again:";
                                            getline(cin, CALLSIGN, '\n');
                                        }
                                        cout << "Input quantity of planes on your ship:" << endl;
                                        while (!getNum(QPFP) || QPFP > 100) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        givenHuman.push_back(human);
                                        givenWeapon.push_back(weaponing);
                                        MainGroup.TableCarryGroup.insert(pair<string, WarShip *>(CALLSIGN, new AircraftCarrier
                                                (HP,SPD,SCF,givenWeapon,QOCM,givenHuman, NAME_SHIP,QPFP)));
                                        MainGroup.countShips++;
                                        givenWeapon.clear();
                                        givenHuman.clear();
                                        break;
                                    }
                                    case 3: {
                                        cout << "Input health:" << endl;
                                        while (!getNum(HP)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        cout << "Input speed:" << endl;
                                        while (!getNum(SPD)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        cout << "Input scope fuel:" << endl;
                                        while (!getNum(SCF)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        cout << "Input type of armament (1-Light and 2-Heavy):" << endl;
                                        while (!getNum(TYPE_ARMAMENT)|| TYPE_ARMAMENT > 2) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        weaponing.type = Armament::getTypeByNum(TYPE_ARMAMENT);
                                        cout << "Input name of armament:" << endl;
                                        getline(cin, NAME_ARMA, '\n');
                                        weaponing.nameOfArmament = NAME_ARMA;
                                        cout << "Input name of ammunition:" << endl;
                                        getline(cin, NAME_AMMO, '\n');
                                        weaponing.nameOfAmmunition = NAME_AMMO;
                                        cout << "Input quantity of ammunition:" << endl;
                                        while (!getNum(AMMO)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        weaponing.ammunition = AMMO;
                                        cout << "Input damage per second:" << endl;
                                        while (!getNum(DMG)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        weaponing.damagePerSec = DMG;
                                        cout << "Input rate of fire:" << endl;
                                        while (!getNum(ROF)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        weaponing.rateOfFire = ROF;
                                        cout << "Input quantity of crew members:" << endl;
                                        while (!getNum(QOCM)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        cout << "Input name of your ship:" << endl;
                                        getline(cin, NAME_SHIP, '\n');
                                        cout << "Input name of capitan:" << endl;
                                        getline(cin, NOC, '\n');
                                        human.NameOurCapitan = NOC;
                                        cout << "Input experience of your cap:" << endl;
                                        while (!getNum(EXP)) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        human.experience = EXP;
                                        cout << "Input rank(Captain2rdRank = 2,Captain1rdRank = 3) of your cap:" << endl;
                                        while (!getNum(RANK)|| RANK > 3 || RANK < 2) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        human.capitansRank = InfoAboutCap::getRankByNum(RANK);
                                        cout << "Input callsign of your ship:" << endl;
                                        getline(cin, CALLSIGN, '\n');
                                        while (MainGroup.SearchCallsignsInGroup(CALLSIGN) == -1 || CALLSIGN.empty()) {
                                            CALLSIGN.clear();
                                            cout << "Incorrect input variant or callsign is used. Try again:";
                                            getline(cin, CALLSIGN, '\n');
                                        }
                                        cout << "Input information about carrying ship:" << endl;
                                        getline(cin, IACarryShip, '\n');
                                        cout << "Input quantity of planes on your ship:" << endl;
                                        while (!getNum(QPFP) || QPFP > 100) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                        givenHuman.push_back(human);
                                        givenWeapon.push_back(weaponing);
                                        MainGroup.TableCarryGroup.insert(pair<string, WarShip *>(CALLSIGN, new AircraftCarryingCruiser
                                                (HP,SPD,SCF,givenWeapon, QOCM,givenHuman,NAME_SHIP,IACarryShip,QPFP)));
                                        MainGroup.countShips++;
                                        givenWeapon.clear();
                                        givenHuman.clear();
                                        break;
                                    }
                                    case 4: {
                                        break;
                                    }
                                    default:
                                        break;
                                }
                            } while (variant != 4);
                            break;
                        }
                        case 2: {
                            cout << "Input callsign of your AircraftCarrier or AircraftCarrierCruiser" << endl;
                            getline(cin, CALLSIGN, '\n');
                            if (MainGroup.SearchAircraftInGroup(CALLSIGN) != 1) {
                                cout << "Not found this AircraftCarrier or AircraftCarrierCruiser in group." <<endl;
                                break;
                            }
                            else {
                                auto SHIP = MainGroup.TableCarryGroup.find(CALLSIGN);
                                do {
                                    if (SHIP->second->CheckoutPlaces(SHIP->second) != -1) {
                                        cout << "Enter the menu number:" << endl;
                                        cout << "1.Add fighter to group." << endl;
                                        cout << "2.Add bomber to group." << endl;
                                        cout << "3.Back." << endl;
                                        cin.clear();
                                        while (!getNum(variant) || variant > 3) {
                                            cout << "Incorrect input variant. Try again:";
                                        }
                                    } else {
                                        cout <<"Not enough places for planes." << endl;
                                        variant = 3;
                                    }
                                    switch (variant) {
                                        case 1: {
                                            cout << "Input callsign of your plane:" << endl;
                                            getline(cin, CALLSIGN_PLANE,'\n');
                                            while (MainGroup.SearchCallsignsInGroup(CALLSIGN_PLANE) == -1 || CALLSIGN_PLANE.empty()) {
                                                CALLSIGN_PLANE.clear();
                                                cout << "Incorrect input variant or callsign is used. Try again:";
                                                getline(cin, CALLSIGN_PLANE, '\n');
                                            }
                                            cout << "Input health:" << endl;
                                            while (!getNum(HP)) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            cout << "Input speed:" << endl;
                                            while (!getNum(SPD)) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            cout << "Input scope fuel:" << endl;
                                            while (!getNum(SCF)) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            cout << "Input type of armament (1-Light and 2-Heavy):" << endl;
                                            while (!getNum(TYPE_ARMAMENT) || TYPE_ARMAMENT > 2) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            weaponing.type = Armament::getTypeByNum(TYPE_ARMAMENT);
                                            cout << "Input name of armament:" << endl;
                                            getline(cin, NAME_ARMA, '\n');
                                            weaponing.nameOfArmament = NAME_ARMA;
                                            cout << "Input name of ammunition:" << endl;
                                            getline(cin, NAME_AMMO, '\n');
                                            weaponing.nameOfAmmunition = NAME_AMMO;
                                            cout << "Input quantity of ammunition:" << endl;
                                            while (!getNum(AMMO)) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            weaponing.ammunition = AMMO;
                                            cout << "Input damage per second:" << endl;
                                            while (!getNum(DMG)) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            weaponing.damagePerSec = DMG;
                                            cout << "Input rate of fire:" << endl;
                                            while (!getNum(ROF)) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            weaponing.rateOfFire = ROF;
                                            givenWeapon.push_back(weaponing);
                                            MainGroup.AddPlaneToGroup(CALLSIGN, new Fighter(HP, SPD, SCF, givenWeapon),CALLSIGN_PLANE);
                                            MainGroup.countPlanes++;
                                            givenWeapon.clear();
                                            break;
                                        }
                                        case 2: {
                                            cout << "Input callsign of your plane:" << endl;
                                            getline(cin, CALLSIGN_PLANE,'\n');
                                            while (MainGroup.SearchCallsignsInGroup(CALLSIGN_PLANE) == -1 || CALLSIGN_PLANE.empty()) {
                                                CALLSIGN_PLANE.clear();
                                                cout << "Incorrect input variant or callsign is used. Try again:";
                                                getline(cin, CALLSIGN_PLANE, '\n');
                                            }
                                            cout << "Input health:" << endl;
                                            while (!getNum(HP)) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            cout << "Input speed:" << endl;
                                            while (!getNum(SPD)) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            cout << "Input scope fuel:" << endl;
                                            while (!getNum(SCF)) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            cout << "Input type of armament (1-Light and 2-Heavy):" << endl;
                                            while (!getNum(TYPE_ARMAMENT) || TYPE_ARMAMENT > 2) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            weaponing.type = Armament::getTypeByNum(TYPE_ARMAMENT);
                                            cout << "Input name of armament:" << endl;
                                            getline(cin, NAME_ARMA, '\n');
                                            weaponing.nameOfArmament = NAME_ARMA;
                                            cout << "Input name of ammunition:" << endl;
                                            getline(cin, NAME_AMMO, '\n');
                                            weaponing.nameOfAmmunition = NAME_AMMO;
                                            cout << "Input quantity of ammunition:" << endl;
                                            while (!getNum(AMMO)) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            weaponing.ammunition = AMMO;
                                            cout << "Input damage per second:" << endl;
                                            while (!getNum(DMG)) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            weaponing.damagePerSec = DMG;
                                            cout << "Input rate of fire:" << endl;
                                            while (!getNum(ROF)) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            weaponing.rateOfFire = ROF;
                                            givenWeapon.push_back(weaponing);
                                            MainGroup.AddPlaneToGroup(CALLSIGN, new Bomber(HP, SPD, SCF, givenWeapon),CALLSIGN_PLANE);
                                            MainGroup.countPlanes++;
                                            givenWeapon.clear();
                                            break;
                                        }
                                        case 3: {
                                            break;
                                        }
                                    }
                                } while (variant != 3);
                            }
                            break;
                        }
                        case 3: {
                            MainGroup.ViewShips();
                            cout << "Input callsign of your ship." << endl;
                            getline(cin, CALLSIGN, '\n');
                            if (MainGroup.SearchCallsignsInGroup(CALLSIGN) != -1) {
                                cout << "Not found this ship in group." <<endl;
                                break;
                            }
                            else{
                                MainGroup.DeleteShipOfGroup(CALLSIGN);
                                cout <<"Element was deleted."<<endl;
                                MainGroup.ViewShips();
                            }
                            break;
                        }
                        case 4: {
                            cout << "Input callsign of your AircraftCarrier or AircraftCarrierCruiser" << endl;
                            getline(cin, CALLSIGN, '\n');
                            if (MainGroup.SearchAircraftInGroup(CALLSIGN) != 1) {
                                cout << "Not found this AircraftCarrier or AircraftCarrierCruiser in group." <<endl;
                                break;
                            }
                            else{
                                auto SHIP = MainGroup.TableCarryGroup.find(CALLSIGN);
                                SHIP->second->ReturnInfoAboutPlanes(SHIP->second);
                                cout <<"Enter the callsign of the plane you want to delete." << endl;
                                getline(cin, CALLSIGN_PLANE, '\n');
                                if (MainGroup.SearchCallsignsInGroup(CALLSIGN_PLANE) != 1) {
                                    MainGroup.DeletePlaneOfGroup(CALLSIGN, CALLSIGN_PLANE);
                                    cout << "Element was deleted." << endl;
                                    SHIP->second->ReturnInfoAboutPlanes(SHIP->second);
                                }
                                else{
                                    cout << "Sry but element not deleted." << endl;
                                    break;
                                }
                            }
                            break;
                        }
                        case 5: {
                            cout << "Enter type of your ship(1-Cruiser,2-AircraftCarrier,3-AircraftCarryingCruiser)." << endl;
                            while (!getNum(TYPE_SHIP) || TYPE_SHIP > 3) {
                                cout << "Incorrect input variant. Try again:";
                            }
                            COUNT = MainGroup.ReturnQuantityOfShipsOfACertainType(TYPE_SHIP);
                            if(COUNT == 0)
                                cout << "Sorry ships of this type are not present." <<endl;
                            else
                                cout << "The number of ships of a given type is: " << COUNT << endl;
                            auto IT_COUNT_SHIPS = MainGroup.TableCarryGroup.begin();
                            COUNT = 0;
                            while(IT_COUNT_SHIPS != MainGroup.TableCarryGroup.end()){
                                COUNT++;
                                IT_COUNT_SHIPS++;
                            }
                            cout << "Table is have " << COUNT << " ships." << endl;
                            break;
                        }
                        case 6: {
                            if((MainGroup.TableCarryGroup.empty()) == 0){
                                MainGroup.ViewShips();
                                cout << "Input callsign of your ship." << endl;
                                getline(cin, CALLSIGN, '\n');
                                if (MainGroup.SearchCallsignsInGroup(CALLSIGN) != -1) {
                                    cout << "Not found this ship in group." <<endl;
                                    break;
                                }
                                else{
                                    auto SHIP = MainGroup.TableCarryGroup.find(CALLSIGN);
                                    if((*SHIP).second->type_ship == 1){
                                        do{
                                            cout << "Enter the menu number:" << endl;
                                            cout << "1.View all fields of your ship." << endl;
                                            cout << "2.Modificate field of your ship." << endl;
                                            cout << "3.Max distance transition your ship." << endl;
                                            cout << "4.Damage Per Minute Armament." << endl;
                                            cout << "5.Back." << endl;
                                            cin.clear();
                                            while (!getNum(variant) || variant > 5) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            switch (variant) {
                                                case 1:{
                                                    cout << "Callsign of your ship:" << endl;
                                                    cout << CALLSIGN << endl;
                                                    (*SHIP).second->ReturnInfoAboutShip((*SHIP).second);
                                                    break;
                                                }
                                                case 2:{
                                                    cout << "Callsign of your ship:" << endl;
                                                    cout << CALLSIGN << endl;
                                                    (*SHIP).second->ReturnInfoAboutShip((*SHIP).second);
                                                    cout <<"What the field you want modificate:"<< endl;
                                                    while (!getNum(variant) || variant > 15) {
                                                        cout << "Incorrect input variant. Try again:";
                                                    }
                                                    (*SHIP).second->ModificationShip(variant,(*SHIP).second);
                                                    (*SHIP).second->ReturnInfoAboutShip((*SHIP).second);
                                                    break;
                                                }
                                                case 3:{
                                                    cout << "Maximum distance :" << endl;
                                                    cout << (*SHIP).second->MaxDistanceTransition((*SHIP).second) << endl;
                                                    break;
                                                }
                                                case 4:{
                                                    cout << "DMG Per Minute armament:" << endl;
                                                    cout << (*SHIP).second->DamagePer1TimeUnitShip((*SHIP).second) << endl;
                                                    break;
                                                }
                                                case 5:{
                                                    break;
                                                }
                                                default:break;
                                            }
                                        }while(variant != 5);
                                    }
                                    if((*SHIP).second->type_ship == 2){
                                        do{
                                            cout << "Enter the menu number:" << endl;
                                            cout << "1.View all fields of your ship." << endl;
                                            cout << "2.Modificate field of your ship." << endl;
                                            cout << "3.Information about planes." << endl;
                                            cout << "4.Modificate planes on the ship." << endl;
                                            cout << "5.Max distance transition your ship." << endl;
                                            cout << "6.Damage Per Minute All Planes." << endl;
                                            cout << "7.Back." << endl;
                                            cin.clear();
                                            while (!getNum(variant) || variant > 7) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            switch (variant) {
                                                case 1:{
                                                    cout << "Callsign of your ship:" <<endl;
                                                    cout << CALLSIGN <<endl;
                                                    (*SHIP).second->ReturnInfoAboutShip((*SHIP).second);
                                                    break;
                                                }
                                                case 2:{
                                                    cout << "Callsign of your ship:" << endl;
                                                    cout << CALLSIGN << endl;
                                                    (*SHIP).second->ReturnInfoAboutShip((*SHIP).second);
                                                    cout <<"What the field you want modificate:"<< endl;
                                                    while (!getNum(variant) || variant > 15) {
                                                        cout << "Incorrect input variant. Try again:";
                                                    }
                                                    (*SHIP).second->ModificationShip(variant,(*SHIP).second);
                                                    (*SHIP).second->ReturnInfoAboutShip((*SHIP).second);
                                                    break;
                                                }
                                                case 3:{
                                                    cout << "Planes on ship :" << endl;
                                                    if((*SHIP).second->ReturnInfoAboutPlanes((*SHIP).second) != 1){
                                                        cout << "Ship is empty." <<endl;
                                                    }
                                                    break;
                                                }
                                                case 4:{
                                                    cout << "Planes on ship :" << endl;
                                                    if((*SHIP).second->ReturnInfoAboutPlanes((*SHIP).second) != 1){
                                                        cout << "Ship is empty." <<endl;
                                                    }
                                                    else {
                                                        cout << "Input callsign of your plane:" << endl;
                                                        getline(cin, CALLSIGN_PLANE, '\n');
                                                        if (MainGroup.SearchCallsignsInGroup(CALLSIGN_PLANE) != 1) {
                                                            (*SHIP).second->ModificatioPlane(CALLSIGN_PLANE, (*SHIP).second);
                                                            (*SHIP).second->ReturnInfoAboutPlanes((*SHIP).second);
                                                        }
                                                        else{
                                                            cout << "Sry but plane not found." <<endl;
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                }
                                                case 5:{
                                                    cout << "Maximum distance :" << endl;
                                                    cout << (*SHIP).second->MaxDistanceTransition((*SHIP).second) << endl;
                                                    break;
                                                }
                                                case 6:{
                                                    cout << "DMG per minute all planes:" << endl;
                                                    cout << (*SHIP).second->DamagePer1TimeUnitPlanes((*SHIP).second) << endl;
                                                    break;
                                                }
                                                case 7:{
                                                    break;
                                                }
                                                default:break;
                                            }
                                        }while(variant != 7);
                                    }
                                    if((*SHIP).second->type_ship == 3){
                                        do {
                                            cout << "Enter the menu number:" << endl;
                                            cout << "1.View all fields of your ship." << endl;
                                            cout << "2.Modificate field of your ship." << endl;
                                            cout << "3.Information about planes." << endl;
                                            cout << "4.Modificate planes on the ship." << endl;
                                            cout << "5.Max distance transition your ship." << endl;
                                            cout << "6.Damage Per Minute All Planes." << endl;
                                            cout << "7.Damage Per Minute Armament." << endl;
                                            cout << "8.Back." << endl;
                                            cin.clear();
                                            while (!getNum(variant) || variant > 8) {
                                                cout << "Incorrect input variant. Try again:";
                                            }
                                            switch (variant) {
                                                case 1: {
                                                    cout << "Callsign of your ship:" << endl;
                                                    cout << CALLSIGN << endl;
                                                    (*SHIP).second->ReturnInfoAboutShip((*SHIP).second);
                                                    break;
                                                }
                                                case 2: {
                                                    cout << "Callsign of your ship:" << endl;
                                                    cout << CALLSIGN << endl;
                                                    (*SHIP).second->ReturnInfoAboutShip((*SHIP).second);
                                                    cout << "What the field you want modificate:" << endl;
                                                    while (!getNum(variant) || variant > 15) {
                                                        cout << "Incorrect input variant. Try again:";
                                                    }
                                                    (*SHIP).second->ModificationShip(variant, (*SHIP).second);
                                                    (*SHIP).second->ReturnInfoAboutShip((*SHIP).second);
                                                    break;
                                                }
                                                case 3: {
                                                    cout << "Planes on ship :" << endl;
                                                    if ((*SHIP).second->ReturnInfoAboutPlanes((*SHIP).second) != 1) {
                                                        cout << "Ship is empty." << endl;
                                                    }
                                                    break;
                                                }
                                                case 4: {
                                                    cout << "Planes on ship :" << endl;
                                                    if ((*SHIP).second->ReturnInfoAboutPlanes((*SHIP).second) != 1) {
                                                        cout << "Ship is empty." << endl;
                                                    } else {
                                                        cout << "Input callsign of your plane:" << endl;
                                                        getline(cin, CALLSIGN_PLANE, '\n');
                                                        if (MainGroup.SearchCallsignsInGroup(CALLSIGN_PLANE) != 1) {
                                                            (*SHIP).second->ModificatioPlane(CALLSIGN_PLANE,
                                                                                             (*SHIP).second);
                                                            (*SHIP).second->ReturnInfoAboutPlanes((*SHIP).second);
                                                        } else {
                                                            cout << "Sry but plane not found." << endl;
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                }
                                                case 5: {
                                                    cout << "Maximum distance :" << endl;
                                                    cout << (*SHIP).second->MaxDistanceTransition((*SHIP).second)
                                                         << endl;
                                                    break;
                                                }
                                                case 6: {
                                                    cout << "DMG per minute all planes:" << endl;
                                                    cout << (*SHIP).second->DamagePer1TimeUnitPlanes((*SHIP).second)
                                                         << endl;
                                                    break;
                                                }
                                                case 7: {
                                                    cout << "DMG Per Minute armament:" << endl;
                                                    cout << (*SHIP).second->DamagePer1TimeUnitShip((*SHIP).second) << endl;
                                                    break;
                                                }
                                                case 8: {
                                                    break;
                                                }
                                                default:
                                                    break;
                                            }
                                        }while(variant != 8);
                                    }
                                }
                            }
                            else{
                                cout<<"Table Group is empty" <<endl;
                            }
                            break;
                        }
                        case 7: {
                            if((MainGroup.TableCarryGroup.empty()) == 0)
                                MainGroup.ViewShips();
                            else{
                                cout<<"Table Group is empty" <<endl;
                            }
                            break;
                        }
                        case 8: {
                            MainGroup.ViewShips();
                            cout << "Input callsign of your ship." << endl;
                            getline(cin, CALLSIGN, '\n');
                            if (MainGroup.SearchAircraftInGroup(CALLSIGN) != 1) {
                                cout << "Not found this AircraftCarrier or AircraftCarrierCruiser in group." <<endl;
                                break;
                            }
                            else{
                                cout << "Planes on ship :" << endl;
                                auto SHIP = MainGroup.TableCarryGroup.find(CALLSIGN);
                                if ((*SHIP).second->ReturnInfoAboutPlanes((*SHIP).second) != 1) {
                                    cout << "Ship is empty." << endl;
                                    break;
                                }
                                else {
                                    cout << "Input callsign of your plane:" << endl;
                                    getline(cin, CALLSIGN_PLANE, '\n');
                                    if (MainGroup.SearchCallsignsInGroup(CALLSIGN_PLANE) != 1) {
                                        cout << "Input callsign of ship to transfer." << endl;
                                        getline(cin,CALLSIGN_TRANSFER,'\n');
                                        while (MainGroup.SearchAircraftInGroup(CALLSIGN_TRANSFER) != 1) {
                                            CALLSIGN_TRANSFER.clear();
                                            cout << "Not found this AircraftCarrier or AircraftCarrierCruiser in group." <<endl;
                                            getline(cin, CALLSIGN_TRANSFER, '\n');
                                        }
                                        if(MainGroup.AirplaneTransfer(CALLSIGN,CALLSIGN_PLANE,CALLSIGN_TRANSFER)== 1){
                                            cout << "Plane was transfered" << endl;
                                        }
                                        else{
                                            cout << "Plane not transfered" << endl;
                                        }
                                    } else {
                                        cout << "Sry but plane not found." << endl;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 9: {
                            break;
                        }
                        default:
                            break;
                    }
                } while (variant != 9);
                break;
            }
            case 2: {
                if(!MainGroup.TableCarryGroup.empty()) {
                    cout << "Input count of planes:" << endl;
                    while (!getNum(PLANES)) {
                        cout << "Incorrect input variant. Try again:";
                    }
                    CarrierGroup MainAttackGroup;
                    MainAttackGroup.Copy(MainGroup);
                    CarrierGroup AttackGroup;
                    MAIN_NOC = 1;
                    MAIN_human.NameOurCapitan = MAIN_NOC;
                    MAIN_EXP = 1;
                    MAIN_human.experience = MAIN_EXP;
                    MAIN_RANK = 6;
                    MAIN_human.capitansRank = InfoAboutCap::getRankByNum(MAIN_RANK);
                    MAIN_givenHuman.push_back(MAIN_human);
                    POD = 1;
                    DESTINATION = 1;
                    DISBETPOINT = 1;
                    AttackGroup.InputInfo(MAIN_givenHuman, DISBETPOINT, DESTINATION, POD);
                    CALLSIGN = 1;
                    NAME_SHIP = 1;
                    TYPE_ARMAMENT = 1;
                    weaponing.type = Armament::getTypeByNum(TYPE_ARMAMENT);
                    NAME_ARMA = 1;
                    weaponing.nameOfArmament = NAME_ARMA;
                    NAME_AMMO = 1;
                    weaponing.nameOfAmmunition = NAME_AMMO;
                    AMMO = 1;
                    weaponing.ammunition = AMMO;
                    DMG = 1;
                    weaponing.damagePerSec = DMG;
                    ROF = 1;
                    weaponing.rateOfFire = ROF;
                    NOC = 1;
                    human.NameOurCapitan = NOC;
                    EXP = 1;
                    human.experience = EXP;
                    RANK = 2;
                    human.capitansRank = InfoAboutCap::getRankByNum(RANK);
                    givenHuman.push_back(human);
                    givenWeapon.push_back(weaponing);
                    AttackGroup.TableCarryGroup.insert(pair<string, WarShip *>(CALLSIGN, new AircraftCarrier
                            (1, 1, 1, givenWeapon, 1, givenHuman, NAME_SHIP, PLANES)));
                    AttackGroup.InputingAttackGroup(PLANES,CALLSIGN);
                    if(MainGroup.Attack(MainAttackGroup,AttackGroup) == 1){
                        cout << "You winner!" << endl;
                    }
                    else{
                        cout <<"Bot winner!" << endl;
                    }
                    AttackGroup.TableCarryGroup.clear();
                    MainAttackGroup.TableCarryGroup.clear();
                    givenHuman.clear();
                    givenWeapon.clear();
                    MAIN_givenHuman.clear();
                }
                else{
                    cout <<"Sorry but your aircrafting group is empty."<< endl;
                }
                break;
            }
            case 3: {
                return 0;
            }
            default:break;
        }
    }while (variant != 3);
    return 0;
}
