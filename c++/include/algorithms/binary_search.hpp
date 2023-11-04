#pragma once

#include "../list_interface.hpp"


template<typename T>
bool binarySearch (ListInterface<T>& array, T& target, size_t& targetPosition) {
    bool targetFound(false);
    int startPosition(0), endPosition(array.length() - 1);

    while (startPosition < endPosition) {
        auto searchPosition = (endPosition - startPosition) / 2 + startPosition;
        if (target < array[searchPosition]) {
            endPosition = searchPosition - 1;
        }
        else if (target > array[searchPosition]) {
            startPosition = searchPosition + 1;
        }
        else [[unlikely]] {
            targetPosition = searchPosition;
            return true;
        }
    }
    if (array[startPosition] == target) {
        targetPosition = startPosition;
        targetFound = true;
    }

    return targetFound;
}
