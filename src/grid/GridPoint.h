//
// Created by Thijs on 06/04/2019.
//

#ifndef GRIDPHYSICS_GRIDPOINT_H
#define GRIDPHYSICS_GRIDPOINT_H

#include <array>
#include <vector>
#include "../utils/Constants.h"
#include "../utils/Color.h"

namespace grid {

class GridPoint {
    private:

    public:
        const int thisX;
        const int thisY;
        bool noBoundary;
        using Color = utils::Color;
        std::vector<int> ints;
        std::vector<double> doubles;

        std::vector<int> tempInts;
        std::vector<double> tempDoubles;
};

}

#endif //GRIDPHYSICS_GRIDPOINT_H
