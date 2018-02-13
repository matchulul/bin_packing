

#include "../include/smartFirstFit.h"
#include <iostream>
#include <cmath>
#include <numeric>

Bin *smartFirstFit::nextEmptyBin(bool new_alloc, int empty_position){
    if(new_alloc){
        Bin *new_bin = new Bin();
        bins.push_back(*new_bin);
        return new_bin;

    }
    else {
        return &bins[empty_position];
    }
    
}

int smartFirstFit::packBins(){

    int number_of_bins = 0;
    first_empty_bin = bins[0];
    less_half_empty_bin = NULL;
    int empty_bin_counter = 1; // Start at 1, since we just grabbed 0.
    int current_bin_max = estimateBins();
    bool new_alloc = false;

    for(auto obj : bin_objects){
        if (empty_bin_counter >= current_bin_max){
            new_alloc = true;
        }
        if (obj.size() > 0.5){ // Big object, put it in the empty one, and increment.
            first_empty_bin.insertBinObject(obj);
            first_empty_bin = *nextEmptyBin(new_alloc, empty_bin_counter);
            empty_bin_counter++;
            number_of_bins++;
        }
        else{ // Object is < 0.5 in size.
            if (less_half_empty_bin){ //We have a less than half empty bin on hand.
                less_half_empty_bin->insertBinObject(obj);
                if (less_half_empty_bin->total_weight > 0.5){
                    less_half_empty_bin = NULL;
                }
            }
            else{ //No half empty bin, put it in an empty bin
                //Need an address here so that I can test nullity in the simplest way.
                less_half_empty_bin = nextEmptyBin(new_alloc, empty_bin_counter); 
                less_half_empty_bin->insertBinObject(obj);
                number_of_bins++;
                empty_bin_counter++;
            }
        }
    }
    return number_of_bins;
}

