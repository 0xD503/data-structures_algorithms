#pragma once

#include <cstdint>
#include "set_interface.hpp"
#include "dynamic_array.hpp"
#include "algorithms/hash.hpp"



template<typename T, size_t factor = 2>
class HashTable : public SetInterface<T> {
    public:
        //HashTable();
        HashTable(size_t bucketsNum);
        virtual ~HashTable() override;

        inline size_t length () const noexcept { return length__; };

        bool clear ();

        bool insert (const T& val) noexcept;
        bool remove (const T& val) noexcept;

        bool contains (const T& val) const noexcept;

        bool reserve (const size_t bucketsNum);

    private:
        DynamicArray<T *> table__{};
        size_t length__{};

        inline size_t calculateIndex__ (const T& val) {
            return alg::hash::hashFNV_1_a(static_cast<uint8_t *>(&val),
                                          sizeof(val)) % table__.length();
        }
};


// template<typename T>
// HashTable<T>::HashTable() : SetInterface<T>() {
//     //
// }

template<typename T>
HashTable<T>::HashTable(size_t bucketsNum) : SetInterface<T>(), table__(bucketsNum) {
    //
}

template<typename T>
HashTable<T>::~HashTable() {
    clear();
}


template<typename T>
bool HashTable<T>::clear() {
    table__.clear();
    length__ = 0;
}


template<typename T>
bool HashTable<T>::insert(const T& val) noexcept {
    size_t index = calculateIndex__(val);

    // if (table__[index] == nullptr) {
    //     table__[index] = &val;
    // }
    // else {
    //     reserve(table__._length * factor);
    //     // rehash table elements
    // }
}

template<typename T>
bool HashTable<T>::remove(const T& val) noexcept {
    bool removed(false);
    size_t index = calculateIndex__(val);

    if (table__[index] != nullptr) {
        delete table__[index];
        removed = true;
    }

    return removed;
}


template<typename T>
bool HashTable<T>::contains(const T& val) const noexcept {
    bool inserted(false);
    size_t index = calculateIndex__(val);

    if (table__[index] != nullptr) {
        inserted = true;
    }

    return inserted;
}


template<typename T>
bool HashTable<T>::reserve (const size_t bucketsNum) {
    table__.resize(bucketsNum);
}
