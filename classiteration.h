//
// Created by Zver on 29.11.2017.
//

#ifndef LABASOLO4_CLASSITERATION_H
#define LABASOLO4_CLASSITERATION_H

#include "mainhead.h"

namespace classiteration{

    class ClassIteration{
    public:
        ClassIteration() {};
        ~ClassIteration() {};

        int ReturnViewerByCallsign();

        int ReturnQuantityOfCrewGroup();

        int AddElement();

        int DeleteElement();

        int OutputOurTable();
    };
}

#endif //LABASOLO4_CLASSITERATION_H
