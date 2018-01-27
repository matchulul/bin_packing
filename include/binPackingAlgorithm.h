
#ifndef BINPACKING_ALGORITHM_H
#define BINPACKING_ALGORITHM_H

#include "bin.h"
#include "binObjectFactory.h"


class binPackingAlgorithm {

public:
    binPackingAlgorithm(int n_objects, distType dist);

    std::vector<Bin> bins;
    binObjectVector bin_objects;
    binObjectFactory factory;
    int bin_count() { return bins.size(); };
    virtual int packBins() = 0;

};





#endif //BINPACKING_ALGORITHM_H