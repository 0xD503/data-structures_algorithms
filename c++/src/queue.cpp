#include "queue.hpp"


template<typename T>
Queue<T>::Queue(const size_t capacity) : _deque(capacity) {
    //
}

template<typename T>
Queue<T>::Queue(const size_t len, const T& fillValue) : _deque(len, fillValue) {
    //
}


template<typename T>
bool Queue<T>::add(const T& val) {
    return (_deque.addBack(val));
}

template<typename T>
bool Queue<T>::remove() {
    return (_deque.removeFront());
}


/// template types declaration
template class Queue<char>;
template class Queue<short>;
template class Queue<int>;
template class Queue<long>;
