
#include "../include/binPackingAlgorithm.h"

//Generate n binObjects, simple constructor
binPackingAlgorithm::binPackingAlgorithm(int n_objects, distType dist){
    bin_objects = factory.generateN(n_objects, dist);
}
