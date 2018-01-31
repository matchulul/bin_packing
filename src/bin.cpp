
#include "../include/bin.h"
#include <iostream>

Bin::Bin(binObjectVector _bin_objects){
    bin_objects = _bin_objects;
    for(auto obj : bin_objects){
        total_weight += obj.size();
    }

}

bool Bin::insertBinObject(binObject object){
    if (object.size() + total_weight > bin_capacity){
        return false;
    }
    else {
        bin_objects.push_back(object);
        total_weight += object.size();

        return true;
    }

}
