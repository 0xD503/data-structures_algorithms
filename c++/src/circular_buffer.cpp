#include "circular_buffer.hpp"


template<typename T>
CircularBuffer<T>::CircularBuffer(const size_t maxLen,
                                  const bool overwritable) :
    maxLength_(maxLen), queue_(maxLength_), overwritable_(overwritable) {
    //
}


template<typename T>
bool CircularBuffer<T>::get(T& dest) noexcept {
    bool success(queue_.front(dest));
    if (success) {
        queue_.remove();
    }

    return (success);
}

template<typename T>
bool CircularBuffer<T>::put(const T& val) noexcept {
    bool success(false);

    if (queue_.length() < maxLength_) {
        success = queue_.add(val);
    } else if (isOverwritable()) {
#warning "undone"
    }

    return (success);
}


template class CircularBuffer<char>;
template class CircularBuffer<short>;
template class CircularBuffer<int>;
template class CircularBuffer<long>;

// template class CircularBuffer<int8_t>;
// template class CircularBuffer<int16_t>;
// template class CircularBuffer<int32_t>;
// template class CircularBuffer<int64_t>;

// template class CircularBuffer<uint8_t>;
// template class CircularBuffer<uint16_t>;
// template class CircularBuffer<uint32_t>;
// template class CircularBuffer<uint64_t>;
