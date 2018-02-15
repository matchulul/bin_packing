
#include "../include/binObjectFactory.h"
#include <iostream>
#include <random>

/* A small utility function to chop distribution draws to be between a certain
 * number pop it in a namespace until I have enough utility functions to justify
 * a separate file
 */
namespace {
float limit_range(float n, float min_, float max_)
{
    if (n > min_ && n < max_) {
        return n;
    }
    else if (n < min_) {
        return min_;
    }
    else {
        return max_;
    }
}
} // namespace

/*
 * generateN : return a vector of n bin objects,
 *             pulled from a distribution dist
 */
binObjectVector binObjectFactory::generateN(int n, distType dist)
{
    binObjectVector bin_vec;
    for (int i = 0; i < n; i++) {
        bin_vec.push_back(generateBinObject(dist));
    }
    return bin_vec;
}

/*
 * Generate a single bin object by pulling from the respective distribution.
 * If the distribution is unimplemented, exit immediately.
 */
binObject binObjectFactory::generateBinObject(distType dist)
{
    float object_size = 0;
    switch (dist) {
    case distType::normal:
        object_size = limit_range(normal_dist(generator), OBJSIZE_MIN, OBJSIZE_MAX);
        break;
    case distType::uniform:
        object_size = limit_range(uniform_dist(generator), OBJSIZE_MIN, OBJSIZE_MAX);
        break;
    default:
        std::cout << "Unimplemented distribution for binObjectFactory\n";
        exit(1);
    }
    return binObject(object_size);
}
