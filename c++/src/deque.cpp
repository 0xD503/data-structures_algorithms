#include "deque.hpp"


template<typename T>
Deque<T>::Deque(const size_t len, const T& fillValue) {
    for (size_t i(0); i < len; i++) {
        addFront(fillValue);
    }
}
template<typename T>
Deque<T>::Deque(const size_t capacity) {
    size_t half = capacity / 2;
    _frontArray.resize(half);
    if (capacity & 0x01) {
        half++;
    }
    _backArray.resize(half);
}

template<typename T>
Deque<T>::~Deque() {
    clear();
}


template<typename T>
bool Deque<T>::front (T& val) const noexcept {
    bool success(false);

    if (not _frontArray.empty()) {
        success = _frontArray.back(val);
    }
    else if (not _backArray.empty()) {
        success = _backArray.front(val);
    }

    return (success);
}

template<typename T>
bool Deque<T>::back (T& val) const noexcept {
    bool success(false);

    if (not _backArray.empty()) {
        success = _backArray.back(val);
    }
    else if (not _frontArray.empty()) {
        success = _frontArray.front(val);
    }

    return (success);
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
