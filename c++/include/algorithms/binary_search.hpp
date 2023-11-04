#pragma once

#include "cstddef"
// #include "list_interface.hpp"


template<typename T, typename ArrayType>
bool binarySearch (ArrayType<T>& array, T& target, size_t& targetPosition) {
    bool targetFound(false);
    size_t startPosition(0);
    auto endPosition(array.size() - 1);
    auto searchPosition = (endPosition - startPosition) / 2 + startPosition;

    while (startPosition <= endPosition) {
        //auto searchPosition = (endPosition - startPosition) / 2 + startPosition;
        if (target < array[searchPosition]) {
            endPosition = searchPosition - 1;
        }
        else if (target > array[searchPosition]) {
            startPosition = searchPosition + 1;
        }
        else [[unlikely]] {
            break;
        }
        searchPosition = (endPosition - startPosition) / 2 + startPosition;
    }
    // if (array[startPosition] == target) {
    //     targetPosition = startPosition;
    //     targetFound = true;
    // }
    if (array[searchPosition] == target) {
        targetPosition = searchPosition;
        targetFound = true;
    }

    return targetFound;
}

// template<typename T>
// size_t binarySearch (ListInterface<T> list, T& val) {
//     size_t n = list.length() / 2;

//     if (list.length() > 0) {
//         T currVal = list[n];
//         if (currVal < val) {
//             binarySearch(list, val);
//         }
//         else if (currVal > val) {
//             //
//         }
//     }

//     return (n);
// }

// template<typename T>
// size_t binarySearch (const T *list, size_t length, const T& val) {
//     size_t n = length / 2;

//     if (length > 0) {
//         T currVal = list[n];
//         if (currVal < val) {
//             binarySearch(, val);
//         }
//         else if (currVal > val) {
//             //
//         }
//     }

//     return (n);
// }
