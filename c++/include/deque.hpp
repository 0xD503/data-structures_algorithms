#pragma once

#include "deque_interface.hpp"
#include "dynamic_array.hpp"


template<typename T>
class Deque : public DequeInterface<T> {
    public:
        Deque() = default;
        Deque(const size_t capacity);
        Deque(const size_t len, const T& fillValue);
        ~Deque() override;

        inline size_t length () const noexcept override {
            return (_frontArray.length() + _backArray.length());
        }

        bool front (T& val) const noexcept override;
        bool back (T& val) const noexcept override;

        /// getters/setters
        const T& operator[] (size_t index) const override;
        T& operator[] (size_t index) override;

        bool get (size_t index, T& dest) const noexcept override;
        bool set (size_t index, const T& val) noexcept override;

        virtual bool swap (size_t index_1, size_t index_2) noexcept override;

        bool addFront (const T& val) override;
        bool removeFront () override;
        bool addBack (const T& val) override;
        bool removeBack () override;

        bool clear () override;

    protected:
        DynamicArray<T> _frontArray {};
        DynamicArray<T> _backArray {};
};



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
bool Deque<T>::front(T& val) const noexcept {
    bool success(get(0, val));

    return (success);
}

template<typename T>
bool Deque<T>::back(T& val) const noexcept {
    bool success(get(length() - 1, val));

    return (success);
}


template<typename T>
inline const T& Deque<T>::operator[] (size_t index) const {
    const T& returnValue = (index < _frontArray.length()) ?
        _frontArray[_frontArray.length() - 1 - index]
        : _backArray[index - _frontArray.length()];

    return (returnValue);
}

template<typename T>
inline T& Deque<T>::operator[] (size_t index) {
    T& returnValue = (index < _frontArray.length()) ?
        _frontArray[_frontArray.length() - 1 - index]
        : _backArray[index - _frontArray.length()];

    return (returnValue);
}


template<typename T>
bool Deque<T>::get(size_t index, T& dest) const noexcept {
    bool success(false);

    if (index < _frontArray.length()) {
        success = _frontArray.get(_frontArray.length() - 1 - index, dest);
    } else if (index < length()) {
        size_t backId(index - _frontArray.length());
        success = _backArray.get(backId, dest);
    }

    return (success);
}

template<typename T>
bool Deque<T>::set(size_t index, const T& val) noexcept {
    bool success(false);

    if (index < _frontArray.length()) {
        success = _frontArray.set(_frontArray.length() - 1 - index, val);
    } else if (index < length()) {
        size_t backId(index - _frontArray.length());
        success = _backArray.set(backId, val);
    }

    return (success);
}


template<typename T>
bool Deque<T>::swap (size_t index_1, size_t index_2) noexcept {
    bool success(false);

    if (index_1 != index_2) {
        T temp, val;
        if (not get(index_1, temp)) [[unlikely]] {
            goto end;
        }
        if (not get(index_2, val)) [[unlikely]] {
            goto end;
        }
        set(index_1, val);
        set(index_2, temp);
        success = true;
    }

end:
    return (success);
}


template<typename T>
bool Deque<T>::addFront(const T& val) {
    return (_frontArray.append(val));
}

template<typename T>
bool Deque<T>::removeFront() {
    bool success;

    if (not _frontArray.empty()) {
        success = _frontArray.remove(_frontArray.length() - 1);
    } else {
        success = _backArray.remove(0);
    }

    return (success);
}

template<typename T>
bool Deque<T>::addBack(const T& val) {
    return (_backArray.append(val));
}

template<typename T>
bool Deque<T>::removeBack() {
    bool success;

    if (not _backArray.empty()) {
        success = _backArray.remove(_backArray.length() - 1);
    } else {
        success = _frontArray.remove(0);
    }

    return (success);
}


template<typename T>
bool Deque<T>::clear() {
    bool status;

    status = _frontArray.clear();
    status = _backArray.clear() or status;

    return (status);
}
