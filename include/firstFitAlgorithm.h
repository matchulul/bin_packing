
#ifndef BINPACKING_FIRST_FIT_ALGORITHM_H
#define BINPACKING_FIRST_FIT_ALGORITHM_H

#include "algorithm.h"
#include "bin.h"
#include "binObjectFactory.h"

/*
 * firstFitAlgorithm.h
 * purpose: An implementation class of naive first fit
 */
class firstFitAlgorithm : public Algorithm {
public:
    firstFitAlgorithm() = default;
    firstFitAlgorithm(int n_objects, distType dist);

    int num_objects;
    distType obj_dist;

    void reset();
    virtual int packBins();
    int count_objects() { return num_objects; };
    int estimateBins();
    void insertNewBin(binObject obj);
};

#endif // BINPACKING_FIRST_FIT_ALGORITHM_H