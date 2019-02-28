//
// Created by Zver on 28.11.2017.
//
#include "warplane.h"

using namespace std;
using namespace warplane;

namespace warplane{
    int WarPlane::CheckoutArmament(){
        if(countWeapons == 3){
            return -1;
        }
        else
            return 1;
    }
}
