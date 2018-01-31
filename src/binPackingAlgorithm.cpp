
#include "../include/binPackingAlgorithm.h"
#include <numeric>
#include <iostream>
#include <cmath>


//Generate n binObjects, simple constructor
binPackingAlgorithm::binPackingAlgorithm(int n_objects, distType dist){
    num_objects = n_objects;
    obj_dist = dist;
    bin_objects = factory.generateN(n_objects, dist);
}

void binPackingAlgorithm::reset(){
    bin_objects = factory.generateN(num_objects, obj_dist);
    bins.clear();

}

int binPackingAlgorithm::packBins(){
    return 0;
}