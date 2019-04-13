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
#include "../utils/Constants.h"

#include "../grid/GridPoint.h"
#include "../grid/Grid.h"

namespace utils {
class Color;
}

namespace grid {
class Grid;
class GridPoint;
}

namespace window {

class Window {
    private:
        using Grid = grid::Grid;
        using GridPoint = grid::GridPoint;
        using Color = utils::Color;

        static Grid* grid;
        static std::mutex gridMutex;

    public:
        static unsigned char* image;

        static void setGrid(Grid* newGrid) {
            std::lock_guard<std::mutex> lock(gridMutex);
            grid = newGrid;
        }

        static Grid* getGrid() {
            Grid* _grid;
            {
                std::lock_guard<std::mutex> lock(gridMutex);
                _grid = grid->copyGrid();
            }
            return _grid;
        }

        static void initialize() {
            delete[] image;
            image = new unsigned char[4 * WIDTH * HEIGHT];
        }
};

grid::Grid* Window::grid = grid;
unsigned char* Window::image;

} //window

#endif //GRIDPHYSICS_WINDOW_H
