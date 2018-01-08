
#ifndef BINPACKING_BIN_H
#define BINPACKING_BIN_H

#include "../include/binObject.h"
#include <vector>


typedef std::vector<binObject> binObjectVector;

class Bin {

    Bin() = default;
    Bin(binObjectVector _bin_objects) : bin_objects(_bin_objects) {};
    Bin(float _bin_capacity) : bin_capacity(_bin_capacity)
public:
    float total_weight;
    float bin_capacity = 1;
    binObjectVector bin_objects;
    bool insertBinObject(binObject object);
};


#endif // BINPACKING_BIN_H