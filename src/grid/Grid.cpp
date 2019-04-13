//
// Created by Thijs on 11/04/2019.
//

#include "Grid.h"

namespace grid {

std::array<std::array<GridPoint*, HEIGHT>, WIDTH> Grid::getGrid() {
    return grid;
}



}