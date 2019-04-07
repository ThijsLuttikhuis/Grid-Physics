//
// Created by Thijs on 06/04/2019.
//

#ifndef GRIDPHYSICS_GRIDPOINT_H
#define GRIDPHYSICS_GRIDPOINT_H

#include <array>
#include "../utils/Constants.h"

namespace grid {

class GridPoint {
    private:
        using Array = std::array<std::array<GridPoint, HEIGHT>, WIDTH>;
    public:
        virtual void draw() = 0;
        virtual void update() = 0;
};

}

#endif //GRIDPHYSICS_GRIDPOINT_H
