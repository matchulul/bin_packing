
#include "../include/algorithm.h"

// Quick function to initalize N bins ahead of computation.
void Algorithm::initializeNBins(int n)
{
    for (int i = 0; i < n; i++) {
        bins.push_back(Bin());
    }
}