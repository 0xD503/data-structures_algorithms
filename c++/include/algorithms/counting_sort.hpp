#pragma once

#include <cstddef>
#include <algorithm>


namespace alg::sort::counting {

namespace details {

template<typename T, const T minNumber>
size_t getBucketIndex (const decltype(minNumber)& num) {
    return static_cast<size_t>(num - minNumber);
}

template<typename T, const T minNumber>
decltype(minNumber) getElement (const size_t bucketIndex) {
    return static_cast<decltype(minNumber)>(bucketIndex + minNumber);
}

template<size_t bucketsNum>
void clearBuckets(unsigned int (&buckets)[bucketsNum]) {
    std::fill_n(buckets, bucketsNum, 0);
}

}

/**
 * Counting sort implementation
 *
 * Time complexity: O(n + bucketsNum), where n - size of input array
 * Space complexity: O(bucketsNum) == O(maxNumber - minNumber + 1)
 *
 * Use counting sort when the number of bucket is of the same order
 * as the size of input array:
 *   bucketsNum ~ arr.length()
 **/
template<typename ArrayType, typename T, const T maxNumber, const T minNumber,
         bool ascending = true>
void sort(ArrayType& arr) {
    static constexpr size_t bucketsNum{maxNumber - minNumber + 1};
    static unsigned int buckets[bucketsNum]{};

    details::clearBuckets(buckets);

    for (const auto& elem : arr) {
        buckets[details::getBucketIndex<decltype(minNumber), minNumber>(elem)]++;
    }

    if constexpr (ascending) {
        // for (size_t elemIndex(0), bucketIndex(0); bucketIndex < bucketsNum; bucketIndex++) {
        //     while (buckets[bucketIndex]-- > 0) {
        //         arr[elemIndex++] = details::getElement<decltype(minNumber), minNumber>(bucketIndex);
        //     }
        // }
        for (size_t elemIndex(0), bucketIndex(0); auto& bucket : buckets) {
            while (bucket-- > 0) {
                arr[elemIndex++] = details::getElement<decltype(minNumber),
                                                       minNumber>(bucketIndex);
            }
            bucketIndex++;
        }
    }
    else {
        for (size_t elemIndex(0), bucketIndex(bucketsNum); bucketIndex-- > 0; ) {
            while (buckets[bucketIndex]-- > 0) {
                arr[elemIndex++] = details::getElement<decltype(minNumber), minNumber>(bucketIndex);
            }
        }
    }
}

} /// namespace alg::sort::counting
