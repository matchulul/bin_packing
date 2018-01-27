
#ifndef BINPACKING_BIN_OBJECT_FACTORY_H
#define BINPACKING_BIN_OBJECT_FACTORY_H

#include "../include/binObject.h"
#include "../include/bin.h"
#include "../include/types.h"
#include <random>

enum distType { 
    normal,
    uniform
};

class binObjectFactory {

    std::default_random_engine generator;
    std::normal_distribution<float> normal_dist{0.0, 1.0};
    std::uniform_real_distribution<float> uniform_dist{0.0, 1.0};

    binObjectVector generateN(int n, distType dist);
    binObject generateBinObject(distType dist);

};


#endif // BINPACKING_BIN_OBJECT_FACTORY_H