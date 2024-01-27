#pragma once

#include "set_interface.hpp"
#include "dynamic_array.hpp"
#include "algorithms/hash.hpp"



template<typename T>
class HashTable : public SetInterface<T> {
    public:
        HashTable();
        virtual ~HashTable() override;

        size_t length () const noexcept;

        bool clear ();

        bool insert (const T& val) noexcept;
        bool remove (const T& val) noexcept;

        bool contains (const T& val) const noexcept;

    private:
        DynamicArray<T> table__{};
};


template<typename T>
HashTable<T>::HashTable() : SetInterface<T>() {
    //
}

template<typename T>
HashTable<T>::~HashTable() {
    //
}


template<typename T>
size_t HashTable<T>::length() const noexcept {
    //
}


template<typename T>
bool HashTable<T>::clear() {
    //
}


template<typename T>
bool HashTable<T>::insert(const T& val) noexcept {
    //
}

template<typename T>
bool HashTable<T>::remove(const T& val) noexcept {
    //
}


template<typename T>
bool HashTable<T>::contains(const T& val) const noexcept {
    //
}
