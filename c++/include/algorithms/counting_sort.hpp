#pragma once

#include <cstddef>
#include <algorithm>


namespace alg::sort::counting {

//namespace details {

template<typename T, const T minNumber>
size_t getBucketIndex (const T& num) {
    return static_cast<size_t>(num - minNumber);
}

template<size_t bucketsNum>
void clearBuckets(unsigned int (&buckets)[bucketsNum]) {
    std::fill_n(buckets, bucketsNum, 0);
}

//}

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

    clearBuckets(buckets);

    for (const auto& elem : arr) {
        buckets[getBucketIndex<decltype(minNumber), minNumber>(elem)]++;
    }

    size_t elemIndex(0);
    for (size_t bucketIndex(0); bucketIndex < bucketsNum; bucketIndex++) {
        while (buckets[bucketIndex]-- > 0) {
            arr[elemIndex++] = bucketIndex;
        }
    }
}

} /// namespace alg::sort::counting
