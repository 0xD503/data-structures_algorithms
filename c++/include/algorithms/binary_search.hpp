#pragma once

#include "../list_interface.hpp"


template<typename ArrayType, typename T>
bool binarySearchRecursive (ArrayType& array,
                            int startPosition, int endPosition,
                            T& target, size_t& targetPosition) {
    bool targetFound(false);

    if (startPosition <= endPosition) {
        auto searchPosition((endPosition - startPosition) / 2 + startPosition);
        if (target < array[searchPosition]) {
            endPosition = searchPosition - 1;
            targetFound = binarySearchRecursive(array, startPosition, endPosition,
                                                target, targetPosition);
        }
        else if (target > array[searchPosition]) {
            startPosition = searchPosition + 1;
            targetFound = binarySearchRecursive(array, startPosition, endPosition,
                                                target, targetPosition);
        }
        else [[unlikely]] {
            targetPosition = searchPosition;
            targetFound = true;
        }
    }

    return targetFound;
}

template<typename ArrayType, typename T, bool looped = true>
bool binarySearch (ArrayType& array, T& target, size_t& targetPosition) {
    bool targetFound(false);
    /// endPosition should of signed type, otherwise it might underflow to high values
    int startPosition(0), endPosition(array.length() - 1);
    //int startPosition(0), endPosition(array.size() - 1);     // vector's size() method


    if constexpr (looped) {
        /// looped version of binary search
        while (startPosition <= endPosition) {
            auto searchPosition((endPosition - startPosition) / 2 + startPosition);
            if (target < array[searchPosition]) {
                endPosition = searchPosition - 1;
            }
            else if (target > array[searchPosition]) {
                startPosition = searchPosition + 1;
            }
            else [[unlikely]] {
                targetPosition = searchPosition;
                targetFound = true;
                break;
            }
        }
    }
    else {
        /// use recursive version of binary search
        targetFound = binarySearchRecursive(array, startPosition, endPosition,
                                            target, targetPosition);
    }

    return targetFound;
}
