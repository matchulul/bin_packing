#include "../include/smartFirstFit.h"
#include <cmath>
#include <iostream>
#include <numeric>

/* Function to find the next empty bin.
   If we're still within preallocated bounds, simply return a pointer
   To the next position in the list as specified by empty_position.
   If we have run off the end of the preallocated bins, (new_alloc = True)
   then create a new bin and push it on the vector of bins.

   Must be a pointer for checking nullity in the algorithm.
*/
Bin* smartFirstFit::nextEmptyBin(bool new_alloc, int empty_position)
{
    if (new_alloc) {
        Bin* new_bin = new Bin();
        bins.push_back(*new_bin);
        return new_bin;
    }
    else {
        return &bins[empty_position];
    }
}

/* Smart first fit version of pack bins. Holds on to a < half empty bin and
  the next empty bin, choosing one or the other given the size of the object.
  less than half, put it in the < half empty bin, otherwise put it in the empty
  bin.
*/
int smartFirstFit::packBins()
{
    int number_of_bins = 0;
    first_empty_bin = bins[0]; // First bin.
    less_half_empty_bin = NULL; // Initalize to null
    int empty_bin_counter = 1; // Start at 1, since we just grabbed 0.
    int current_bin_max = estimateBins(); // ceil(S) in this case, as prealloc'd
    // in the parent ctor.
    bool new_alloc = false; // A flag for indicating when we run out of preallocated bins.

    for (auto obj : bin_objects) {
        if (empty_bin_counter >= current_bin_max) {
            // We;ve run out of prealloc'd bins. any new ones need to be allocated.
            new_alloc = true;
        }
        if (obj.size() > 0.5) {
            // Big object, put it in the empty one, and increment.
            first_empty_bin.insertBinObject(obj);
            first_empty_bin = *nextEmptyBin(new_alloc, empty_bin_counter);
            empty_bin_counter++; // Let up grab the next empty bin
            number_of_bins++;
        }
        else { // Object is < 0.5 in size.
            if (less_half_empty_bin) { // We have a less than half empty bin on hand.
                less_half_empty_bin->insertBinObject(obj);
                if (less_half_empty_bin->total_weight > 0.5) {
                    less_half_empty_bin = NULL;
                }
            }
            else { // No half empty bin, put it in an empty bin
                // Need an address here so that I can test nullity in the simplest way.
                less_half_empty_bin = nextEmptyBin(new_alloc, empty_bin_counter);
                less_half_empty_bin->insertBinObject(obj);
                number_of_bins++;
                empty_bin_counter++;
            }
        }
    }
    return number_of_bins;
}
