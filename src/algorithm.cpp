
#include "../include/algorithm.h"

 void Algorithm::initializeNBins(int n){
    for(int i=0; i<n; i++){
        bins.push_back(Bin());
    }
    
}