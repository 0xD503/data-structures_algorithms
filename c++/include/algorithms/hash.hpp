#pragma once

#include <cstdint>


namespace alg::hash {


template<uint64_t fnvPrime = 0x00000100000001B3,
         uint64_t fnvOffset = 0x00000100000001B3>
uint64_t hashFNV_1_a (uint8_t *data, size_t size)
{
    uint64_t hash = fnvOffset;

    for (size_t i(0); i < size; i++) {
        hash ^= data[i];
        hash *= fnvPrime;
    }

    return hash;
}

}
