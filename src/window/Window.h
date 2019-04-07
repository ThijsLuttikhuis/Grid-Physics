//
// Created by thijs on 27-12-18.
//

#ifndef GRIDPHYSICS_WINDOW_H
#define GRIDPHYSICS_WINDOW_H

#include <iostream>
#include <array>
#include <vector>
#include <memory>
#include <mutex>

#include "../utils/Color.h"
#include "../grid/GridPoint.h"
#include "../utils/Constants.h"

namespace utils {
class Color;
}

namespace grid {
class GridPoint;
}

namespace window {

class Window {
    private:
        using GridPoint = grid::GridPoint;
        using Array = std::array<std::array<GridPoint, HEIGHT>, WIDTH>;
        using Color = utils::Color;

        static Array grid;
        static std::mutex gridMutex;

    public:
        static Color* image;

        static void setGrid(Array gridPoint) {
            std::lock_guard<std::mutex> lock(gridMutex);

            grid = gridPoint;
        }

        static Array getGrid() {
            std::lock_guard<std::mutex> lock(gridMutex);
            Array gridPoint{};
            gridPoint = grid;
            return gridPoint;
        }

        static void initialize() {
            image = new Color[WIDTH * HEIGHT];
        }
};

} //window

#endif //GRIDPHYSICS_WINDOW_H
