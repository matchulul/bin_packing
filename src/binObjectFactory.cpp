
#include <random>
#include <iostream>
#include "../include/binObjectsFactory.h"
#include "../include/types.h"

binObjectVector binObjectFactory::generateN(int n, distType dist){
    binObjectVector bin_vec;
    for (int i = 0; i < n; i++){
        bin_vec.push_back(generateBinObject(dist));
    }
    return bin_vec;
}

binObject binObjectFactory::generateBinObject(distType dist){
    switch(dist) {
    case distType::normal:
        return binObject(normal_dist(generator));
    case distType::uniform:
        return binObject(uniform_dist(generator));
    default:
        std::cout << "Unimplemented distribution for binObjectFactory\n";
        exit(1);
    }

}
