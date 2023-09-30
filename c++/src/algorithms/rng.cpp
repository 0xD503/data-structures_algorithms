#include "algorithms/rng.hpp"


RNG::RNG(std::mt19937::result_type min, std::mt19937::result_type max) : randomGenEngine__(device__()), distribution__(min, max) {
    //
}
