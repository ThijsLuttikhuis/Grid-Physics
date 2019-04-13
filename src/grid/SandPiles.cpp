//
// Created by Thijs on 07/04/2019.
//

#include "SandPiles.h"

namespace grid {

void SandPiles::draw(unsigned char*&image) {
    for (auto &a : grid) {
        for (auto &gp : a) {
            if (gp->ints.empty()) return;

            int index = gp->thisX + gp->thisY * HEIGHT;
            switch (gp->ints[0]) {
            case 1: *(image + index * 4 + 0) = 255;
                break;
            case 2: *(image + index * 4 + 1) = 255;
                break;
            case 3: *(image + index * 4 + 2) = 255;
                break;
            default:
                break;
            }
        }
    };
}

void SandPiles::update() {
    bool pilesFalling = true;
    while (pilesFalling) {
        pilesFalling = false;
        for (auto &a : grid) {
            for (auto &gp : a) {
                if (gp->ints.empty()) return;

                if (gp->ints[0] > 3) {
                    gp->ints[0] -= 4;

                }
            }
        }
    }
}

Grid* SandPiles::copyGrid() {
    Grid* newGrid = new SandPiles(getGrid());
    return newGrid;
}

}
