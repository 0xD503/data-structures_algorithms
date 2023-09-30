#pragma once

#include "set_interface.hpp"


template<typename T>
class SortedSetInterface : public SetInterface<T> {
    public:
        virtual ~SortedSetInterface() override = 0;

        //virtual inline bool find (const T& val, T& dest) const noexcept = 0;
        virtual inline bool find (const T& val, size_t& index) const noexcept = 0;

        inline bool contains (const T& val) const noexcept override {
            size_t dummy;
            return (find(val, dummy));
        };
};


template<typename T>
SortedSetInterface<T>::~SortedSetInterface() {
    //
}
