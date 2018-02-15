
#ifndef BINPACKING_BIN_OBJECT_FACTORY_H
#define BINPACKING_BIN_OBJECT_FACTORY_H

#include "../include/bin.h"
#include "../include/binObject.h"
#include <map>
#include <random>

// constants for now, easily expanded
#define OBJSIZE_MIN 0.01
#define OBJSIZE_MAX 0.99

enum distType { normal,
    uniform };

/*
 * binObjectFactory.h
 * purpose:A factory for producing randomly generated binObjects.
 */
class binObjectFactory {
    /*
   *  I have chosen N(0.5, 0.15) to get some non-uniformly distributed numbers
   *  numbers will be capped between 0.01 and .99 to still maintain the size
   *  0-1 size of the problem, on the off chance a number is generated above
   *  (A very low probability event.)
   */
    std::default_random_engine generator;
    std::normal_distribution<float> normal_dist{ 0.5, 0.15 };
    std::uniform_real_distribution<float> uniform_dist{ 0.0, 1.0 };

public:
    binObjectFactory() { generator.seed(time(0)); }
    binObjectVector generateN(int n, distType dist);
    binObject generateBinObject(distType dist);
};

#endif // BINPACKING_BIN_OBJECT_FACTORY_H