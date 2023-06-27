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
