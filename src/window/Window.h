#include <utility>

//
// Created by thijs on 27-12-18.
//

#ifndef GRIDPHYSICS_WINDOW_H
#define GRIDPHYSICS_WINDOW_H

#include <iostream>
#include <vector>
#include <memory>
#include <mutex>

#include "../utils/Color.h"
#include "../grid/GridPoint.h"

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

        static std::vector<GridPoint> grid;
        static std::mutex gridMutex;

    public:
        static void setGrid(std::vector<GridPoint> gridPoint) {
            std::lock_guard<std::mutex> lock(gridMutex);

            grid = std::move(gridPoint);
        }

        static std::vector<GridPoint> getGrid() {
            std::lock_guard<std::mutex> lock(gridMutex);
            std::vector<GridPoint> gridPoint;
            gridPoint.reserve(width*height);
            gridPoint = grid;
            return gridPoint;
        }

        static Color* image;
        static const short width = 800;
        static const short height = 800;

            static void initialize() {
                image = new Color[width*height];
                grid.reserve(width*height);
        }
};

} //window

#endif //FINDBALL_WINDOW_H
