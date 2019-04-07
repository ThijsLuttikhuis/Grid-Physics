//
// Created by Thijs on 07/04/2019.
//

#ifndef GRIDPHYSICS_SANDPILES_H
#define GRIDPHYSICS_SANDPILES_H

#include "GridPoint.h"

namespace grid {

class SandPiles : public GridPoint {
    private:


    public:
        void draw() override;
        void update() override;

};

}
#endif //GRIDPHYSICS_SANDPILES_H
