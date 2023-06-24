#include "deque.hpp"


template<typename T>
Deque<T>::Deque(const size_t len, const T& fillValue) {
    for (size_t i(0); i < len; i++) {
        addFront(fillValue);
    }
}
template<typename T>
Deque<T>::Deque(const size_t capacity) {
    //
    #warning "not implemented"
}

template<typename T>
Deque<T>::~Deque() {
    clear();
}


template<typename T>
bool Deque<T>::addFront (const T& val) {
    return (_frontArray.append(val));
}

template<typename T>
bool Deque<T>::removeFront () {
    return (_frontArray.remove(_frontArray.length() - 1));
}

template<typename T>
bool Deque<T>::addBack (const T& val) {
    return (_backArray.append(val));
}

template<typename T>
bool Deque<T>::removeBack () {
    return (_backArray.remove(_frontArray.length() - 1));
}


template<typename T>
bool Deque<T>::clear() {
    bool status;

    status = _frontArray.clear();
    status = status and _backArray.clear();

    return (status);
}


template class Deque<long>;
