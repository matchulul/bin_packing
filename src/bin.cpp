
#include "../include/bin.h"
#include <iostream>

/* Constructor for prexisting bin objects.
 *  Needed for creating new bins if we run out
 */
Bin::Bin(binObjectVector _bin_objects)
{
    bin_objects = _bin_objects;
    for (auto obj : bin_objects) {
        total_weight += obj.size();
    }
}

/*
 * Attempt to insert a binObject in to this bin.
 * Returns: False if the object can't fit, True if it can.
 */
bool Bin::insertBinObject(binObject object)
{
    if (object.size() + total_weight > bin_capacity) {
        return false;
    }
    else {
        bin_objects.push_back(object);
        total_weight += object.size();

        return true;
    }
}
