#include "circular_buffer.hpp"


// //template<typename T, size_t maxLength>
// template<typename T>
// //CircularBuffer<T, maxLength>::CircularBuffer() {
// CircularBuffer<T>::CircularBuffer() queue_(maxLength_) {
//     //
// }

template<typename T>
CircularBuffer<T>::CircularBuffer(const size_t maxLen,
                                  const bool overwritable) :
    maxLength_(maxLen), queue_(maxLength_), overwritable_(overwritable) {
    //
}


// template<typename T, size_t maxLength>
// bool CircularBuffer<T, maxLength>::get (T& dest) const noexcept {
template<typename T>
bool CircularBuffer<T>::get(T& dest) noexcept {
    bool success(queue_.front(dest));
    if (success) {
        queue_.remove();
    }

    return (success);
}

// template<typename T, size_t maxLength>
// bool CircularBuffer<T, maxLength>::put (const T& val) noexcept {
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


// template class CircularBuffer<char, 1>;
// template class CircularBuffer<short, 1>;
// template class CircularBuffer<int, 1>;
// template class CircularBuffer<long, 1>;
template class CircularBuffer<char>;
// template class CircularBuffer<short>;
// template class CircularBuffer<int>;
// template class CircularBuffer<long>;
