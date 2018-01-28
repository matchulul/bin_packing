
#include "../include/binPackingAlgorithm.h"
#include <numeric>
#include <iostream>


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
    int j;
    for (int i=0; i<100000000; i++){
        j = 1+1;
    }
    std::cout << j;
    return (int) bin_objects[10].size()*10;
}