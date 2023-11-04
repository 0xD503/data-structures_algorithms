#pragma once

#include "list_interface.hpp"

#include <utility>

#include <cstring>

#include <iostream>


template<typename T>
class DynamicArray : public ListInterface<T> {
    public:
        DynamicArray() = default;
        explicit DynamicArray(const size_t capacity);
        DynamicArray(const size_t length, const T& fillValue);
        DynamicArray(const DynamicArray& darr) = default;
        ~DynamicArray() override;

        inline DynamicArray& operator=(const DynamicArray& other) = default;

        /// memory management
        inline size_t capacity () const noexcept { return (_capacity); }
        inline size_t size () const noexcept override { return (sizeof(T) * _capacity); }
        bool resize (const size_t newSize);
        bool fit ();

        /// accessors
        inline T* data () noexcept { return (_array); }
        inline const T* data () const noexcept { return (_array); }

        /// getters/setters
        inline const T& operator[] (size_t index) const override { return (_array[index]); }
        inline T& operator[] (size_t index) override { return (_array[index]); }

        bool get (const size_t index, T& dest) const noexcept override;
        bool set (const size_t index, const T& val) noexcept override;

        /// modifiers
        bool swap (size_t index_1, size_t index_2) noexcept override;

        bool insert (const size_t index, const T& val) override;
        bool remove (const size_t index) override;

        bool clear () override;

    protected:
        T* _array {};
        size_t _capacity {};

    protected:
        // void _copyArray (T *dest, const T *src, const size_t index, const
        // size_t newLen, const T val);

    private:
        static constexpr size_t MEM_REALLOC_FACTOR = 2;
};



template<typename T>
DynamicArray<T>::DynamicArray(const size_t capacity) :
    _array(new T[capacity]), _capacity(capacity) {
    //
}

template<typename T>
DynamicArray<T>::DynamicArray(const size_t length, const T& fillValue) :
    DynamicArray<T>(length) {
    if (this->_capacity == length) {
        for (size_t i = 0; i < this->_capacity; i++) {
            _array[i] = fillValue;
        }
        this->_length = length;
    }
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    clear();
}


template<typename T>
bool DynamicArray<T>::resize(const size_t newCapacity) {
    bool status = false;

    if ((newCapacity >= this->length()) and (newCapacity != this->_capacity)) {
        T* newArray;
        newArray = new T[newCapacity];

        for (size_t i = 0; i < this->length(); i++) {
            newArray[i] = _array[i];
        }

        delete[] _array;
        _array = newArray;
        this->_capacity = newCapacity;
        status = true;
    }

    return (status);
}

template<typename T>
bool DynamicArray<T>::fit() {
    bool success(resize(this->length()));

    if (not success) {
        std::cerr << "Failed to fit array" << std::endl;
    }

    return (success);
}


template<typename T>
bool DynamicArray<T>::get(const size_t index, T& dest) const noexcept {
    bool success(false);

    if (index < this->length()) {
        dest = _array[index];
        success = true;
    }

    return (success);
}

template<typename T>
bool DynamicArray<T>::set(const size_t index, const T& val) noexcept {
    bool success(false);

    if (index < this->length()) {
        _array[index] = val;
        success = true;
    }

    return (success);
}


template<typename T>
bool DynamicArray<T>::swap(size_t index_1, size_t index_2) noexcept {
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
bool DynamicArray<T>::insert(const size_t index, const T& val) {
    bool success(false);
    const size_t destStart = index + 1;
    const size_t n = this->length() + 1 - destStart;

    if (index > this->length()) {
        goto end;
    }

    if (this->length() >= this->_capacity) {
        size_t newCap = (this->length() + 1) * MEM_REALLOC_FACTOR;
        success = resize(newCap);
        if (not success) {
            std::cerr << "Failed to extend array" << std::endl;
            goto end;
        }
    }

    std::memmove(&_array[destStart], &_array[index], sizeof(T) * n);
    _array[index] = val;

    this->_length++;
    success = true;

end:
    return (success);
}

template<typename T>
bool DynamicArray<T>::remove(const size_t index) {
    bool success(false);

    if (index < this->length()) {
        if ((this->length() - 1) <
            (this->_capacity / (MEM_REALLOC_FACTOR + 1))) {
            if (not resize(this->length() + 1)) {
                std::cerr << "Failed to shrink array" << std::endl;
                goto end;
            }
        }
        const size_t n = this->length() - index - 1;
        std::memmove(&_array[index], &_array[index + 1], sizeof(T) * n);
        this->_length--;
        success = true;
    }

end:
    return (success);
}


template<typename T>
bool DynamicArray<T>::clear() {
    bool done(false);

    if ((this->length() > 0) and (_array != nullptr)) {
        delete[] _array;
        _array = nullptr;
        this->_length = 0;
        this->_capacity = 0;
        done = true;
    }

    return (done);
}
