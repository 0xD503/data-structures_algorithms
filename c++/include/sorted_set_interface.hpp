#pragma once

#include "set_interface.hpp"


template<typename T>
class SortedSetInterface : public SetInterface<T> {
    public:
        virtual ~SortedSetInterface() override = 0;

        virtual bool find (const T& val, T& dest) const noexcept = 0;
};


template<typename T>
SortedSetInterface<T>::~SortedSetInterface() {
    //
}
