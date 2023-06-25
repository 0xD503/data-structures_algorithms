#include "deque.hpp"


template<typename T>
Deque<T>::Deque(const size_t capacity) : Deque<T>() {
    size_t half = capacity / 2;
    _frontArray.resize(half);
    if (capacity & 0x01) {
        half++;
    }
    _backArray.resize(half);
}

template<typename T>
Deque<T>::Deque(const size_t len, const T& fillValue) : Deque<T>(len) {
    size_t half = len / 2;
    for (size_t i(0); i < half; i++) {
        addFront(fillValue);
    }
    if (len & 0x01) {
        half++;
    }
    for (size_t i(0); i < half; i++) {
        addBack(fillValue);
    }
}

template<typename T>
Deque<T>::~Deque() {
    clear();
}


template<typename T>
bool Deque<T>::front (T& val) const noexcept {
    bool success;

    if (not _frontArray.empty()) {
        success = _frontArray.back(val);
    }
    else {
        success = _backArray.front(val);
    }

    return (success);
}

template<typename T>
bool Deque<T>::back (T& val) const noexcept {
    bool success;

    if (not _backArray.empty()) {
        success = _backArray.back(val);
    }
    else {
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
    bool success;

    if (not _frontArray.empty()) {
        success = _frontArray.remove(_frontArray.length() - 1);
    }
    else {
        success = _backArray.remove(0);
    }

    return (success);
}

template<typename T>
bool Deque<T>::addBack (const T& val) {
    return (_backArray.append(val));
}

template<typename T>
bool Deque<T>::removeBack () {
    bool success;

    if (not _backArray.empty()) {
        success = _backArray.remove(_backArray.length() - 1);
    }
    else {
        success = _frontArray.remove(0);
    }

    return (success);
}


template<typename T>
bool Deque<T>::clear() {
    bool status;

    status = _frontArray.clear();
    status = status and _backArray.clear();

    return (status);
}


template class Deque<long>;
template class Deque<char>;
