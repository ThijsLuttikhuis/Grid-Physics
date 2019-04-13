//
// Created by Thijs on 07/04/2019.
//

#ifndef GRIDPHYSICS_SANDPILES_H
#define GRIDPHYSICS_SANDPILES_H

#include "Grid.h"

namespace grid {
/**
 *  ints[0] = value of sandpile
 *
**/
class SandPiles : public Grid {
    private:


    public:
        explicit SandPiles(std::array<std::array<GridPoint*, HEIGHT>, WIDTH> grid)
                :Grid(grid) {};

        void draw(unsigned char* &image) override;
        void update() override;
        Grid* copyGrid() override;
};

}
#endif //GRIDPHYSICS_SANDPILES_H
