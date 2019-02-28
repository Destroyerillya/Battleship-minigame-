//
// Created by Zver on 28.11.2017.
//

#ifndef LABASOLO4_MAINHEAD_H
#define LABASOLO4_MAINHEAD_H

#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <limits>
#include <random>
#include <cmath>
//#include <vector>
#include "vec.h"

using namespace std;

namespace mainhead{

    template <class T>

    int getNum(T &a) {
        std::cin >> a;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (a > 0) {
            return 1;
        } else {
            return 0;
        }
    }
}

#endif //LABASOLO4_MAINHEAD_H
