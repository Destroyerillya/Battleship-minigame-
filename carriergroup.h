//
// Created by Zver on 29.11.2017.
//

#ifndef LABASOLO4_CARRIERGROUP_H
#define LABASOLO4_CARRIERGROUP_H

#include "warship.h"
#include "classiteration.h"
#include "warplane.h"

using namespace std;
using namespace warship;
using namespace classiteration;
using namespace warplane;

namespace carriergroup {

    class CarrierGroup {
    public:
        vec::vector <InfoAboutCap> MAINCAPFIO;
        string pointOfDeparture;
        string destination;
        unsigned int distanceBetweenPoints;
        unsigned int countShips = 0;
        unsigned int countPlanes = 1;
        map<string, WarShip *> TableCarryGroup;

        CarrierGroup() {};
        ~CarrierGroup() {};

        int InputInfo(vec::vector<InfoAboutCap> , unsigned int , string , string );

        int SearchAircraftInGroup(string );

        int ReturnQuantityOfShipsOfACertainType(unsigned int);

        int DeleteShipOfGroup(string );

        int ViewShips();

        int SearchCallsignsInGroup(string );

        int AddPlaneToGroup(string, WarPlane *, string);
        int DeletePlaneOfGroup(string, string );

        int AirplaneTransfer(string ,string ,string );

        int InputingAttackGroup(unsigned int ,string );

        int Attack(CarrierGroup , CarrierGroup);

        void Copy(CarrierGroup);

        friend class ClassIteration;
        typedef ClassIteration ConstIteration;
    };
}
#endif //LABASOLO4_CARRIERGROUP_H
