
#include "../include/bin.h"


bool Bin::insertBinObject(binObject object){
    if (object.size() + total_weight > bin_capacity){
        return false;
    }
    else{
        bin_objects.push_back(object);
        total_weight += object.size();
    }

    return true;
}
