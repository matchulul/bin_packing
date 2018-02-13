
#include "../include/firstFitAlgorithm.h"
#include <iostream>
#include <cmath>
#include <numeric>

//Generate n binObjects, simple constructor
firstFitAlgorithm::firstFitAlgorithm(int n_objects, distType dist){
    num_objects = n_objects;
    obj_dist = dist;
    bin_objects = factory.generateN(n_objects, dist);
    initializeNBins(estimateBins());
}

void firstFitAlgorithm::reset(){
    bin_objects = factory.generateN(num_objects, obj_dist);
    bins.clear();

}
int firstFitAlgorithm::estimateBins(){

    // The first fit algorithm in this scenario asserts that the optimal
    // Number of bins is ceil(S) where S is the sum of all the objects.

    //initialize S-1 number of bins. The algorithm will increase the number 
    //of bins as needed.
    float obj_sum = 0;
    for(auto obj: bin_objects){
        obj_sum += obj.size();
    }
    return round(ceil(obj_sum));
}

int firstFitAlgorithm::packBins(){

    //Basic brute force approach.
    int number_of_bins = 0;

    for(auto obj : bin_objects){
        auto obj_inserted = false;
        for(std::size_t i=0; i != bins.size(); i++){
            // If a bin is empty, it will always accept the object.
            if (bins[i].isEmpty()){
                bins[i].insertBinObject(obj);
                number_of_bins++;
                obj_inserted = true;
                break;
            }
            if(bins[i].insertBinObject(obj)){
                obj_inserted = true;
                break;
            }
            else {                
                continue; // Not required, but I like being explicit
            }
        }
        if(!obj_inserted) {
            insertNewBin(obj);
            number_of_bins++;
        }
    }
    return number_of_bins;

}

void firstFitAlgorithm::insertNewBin(binObject obj){
    binObjectVector obj_bin = {obj};
    Bin *new_bin = new Bin(obj_bin);
    bins.push_back(*new_bin);
}

