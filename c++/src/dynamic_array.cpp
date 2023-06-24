#include "dynamic_array.hpp"

#include <cstring>
#include <iostream>


using std::clog;
using std::cerr;
using std::endl;

template<typename T>
DynamicArray<T>::DynamicArray(const size_t capacity) :
    DynamicArray<T>() {
    try {
        _array = new T[capacity];
        this->_capacity = capacity;
    } catch (std::bad_alloc& excpt) {
        _array = nullptr;
        cerr << "Failed to construct dynamic array with capacity " << capacity
             << ": " << excpt.what() << endl;
    }
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
bool DynamicArray<T>::resize (const size_t newCapacity) {
    bool status = false;

    if ((newCapacity >= this->_length) and (newCapacity != this->_capacity)) {
        T *newArray;
        try {
            newArray = new T[newCapacity];
        } catch (std::bad_alloc& excpt) {
            cerr << "Failed to allocate resized array" << endl;
            goto end;
        }

        for (size_t i = 0; i < this->_length; i++) {
            newArray[i] = _array[i];
        }

        try {
            delete[] _array;
        } catch (...) {
            cerr << "Failed to destroy old array before resizing" << endl;
            goto end;
        }

        _array = newArray;
        this->_capacity = newCapacity;
        status = true;
    }

end:
    return (status);
}

template<typename T>
bool DynamicArray<T>::fit () {
    bool success(resize(this->_length));

    if (not success) {
        cerr << "Failed to fit array" << endl;
    }

    return (success);
}


template<typename T>
bool DynamicArray<T>::get (const size_t index, T& dest) const noexcept {
    bool success(false);

    if (index < this->length()) {
        dest = _array[index];
        success = true;
    }

    return (success);
}

template<typename T>
bool DynamicArray<T>::set (const size_t index, const T& val) noexcept {
    bool success(false);

    if (index < this->_length) {
        _array[index] = val;
        success = true;
    }

    return (success);
}


template<typename T>
bool DynamicArray<T>::swap (size_t index_1, size_t index_2) noexcept {
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
bool DynamicArray<T>::insert (const size_t index, const T& val) {
    bool success(false);
    const size_t destStart = index + 1;
    const size_t n = this->_length + 1 - destStart;

    if (index > this->_length) {
        goto end;
    }

    if (this->_length >= this->_capacity) {
        size_t newCap = (this->_length + 1) * MEM_REALLOC_FACTOR;
        success = resize(newCap);
        if (not success) {
            cerr << "Failed to extend array" << endl;
            goto end;
        }
    }

    std::memmove(&_array[destStart], &_array[index], n * sizeof(T));
    _array[index] = val;

    this->_length++;
    success = true;

end:
    return (success);
}

template<typename T>
bool DynamicArray<T>::remove (const size_t index) {
    bool success(false);

    if (index < this->_length) {
        if ((this->_length - 1) < (this->_capacity / (MEM_REALLOC_FACTOR + 1))) {
            if (not resize(this->_length + 1)) {
                cerr << "Failed to shrink array" << endl;
                goto end;
            }
        }
        const size_t n = this->_length - index - 1;  /// TODO: TEST IT!!!!!
        std::memmove(&_array[index], &_array[index + 1], n);
        this->_length--;
        success = true;
    }

end:
    return (success);
}


template<typename T>
bool DynamicArray<T>::clear () {
    bool done(true);

    //if (_capacity > 0) {
    try {
        delete[] _array;
    } catch (...) {
        done = false;
        cerr << "Failed to clear dynamic array" << endl;
    }
    this->_length = 0;
    this->_capacity = 0;
    _array = nullptr;
    //}

    return (done);
}


// template<typename T>
// void DynamicArray<T>::_copyArray (T *dest, const T *src, const size_t index, const size_t newLen, const T val) {
//     size_t i;

//     for (i = 0; i < index; i++) {
//         dest[i] = src[i];
//     }
//     dest[i++] = val;
//     for (; i < newLen; i++) {
//         dest[i] = src[i - 1];
//     }
// }


///
template class DynamicArray<long>;
template class DynamicArray<int>;
template class DynamicArray<char>;
