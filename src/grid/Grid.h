//
// Created by Thijs on 11/04/2019.
//

#ifndef GRIDPHYSICS_GRID_H
#define GRIDPHYSICS_GRID_H

#include <array>
#include "GridPoint.h"

namespace grid {

class Grid {
    protected:
        using Color = utils::Color;

        std::array<std::array<GridPoint*, HEIGHT>, WIDTH> grid;
    public:
        explicit Grid(std::array<std::array<GridPoint*, HEIGHT>, WIDTH> grid)
                :grid(grid) {};

        virtual void update() = 0;
        virtual void draw(unsigned char* &image) = 0;
        std::array<std::array<GridPoint*, HEIGHT>, WIDTH> getGrid();
        virtual Grid* copyGrid() = 0;
};

}

#endif //GRIDPHYSICS_GRID_H
