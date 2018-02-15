
#ifndef BINPACKING_ALGORITHM_H
#define BINPACKING_ALGORITHM_H

#include "bin.h"
#include "binObject.h"
#include "binObjectFactory.h"

/*
 * algorithm.h
 * Purpose: Abstract base class for Bin packing solutions
 */
class Algorithm {
public:
    Algorithm()
        : name("Bin Packing"){};

    binVector bins;
    binObjectVector bin_objects;
    binObjectFactory factory;
    std::string name;

    virtual int count_objects() { return 0; };
    void initializeNBins(int n);
};

#endif