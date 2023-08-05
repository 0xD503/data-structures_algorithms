#include "stack.hpp"


template<typename T>
Stack<T>::Stack(const size_t capacity) : _deque(capacity) {
    //
}

template<typename T>
Stack<T>::Stack(const size_t len, const T& fillValue) : _deque(len, fillValue) {
    //
}


template class Stack<long>;
template class Stack<int>;
template class Stack<short>;
template class Stack<char>;
template class Stack<long long>;

// template class Stack<int8_t>;
// template class Stack<int16_t>;
// template class Stack<int32_t>;
// template class Stack<int64_t>;

// template class Stack<uint8_t>;
// template class Stack<uint16_t>;
// template class Stack<uint32_t>;
// template class Stack<uint64_t>;
