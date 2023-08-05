#pragma once

#include "dynamic_container_interface.hpp"


template<typename T>
class SetInterface : public DynamicContainerInterface<T> {
    public:
        virtual ~SetInterface() override = 0;

        virtual inline bool insert (const T& val) noexcept = 0;
        virtual inline bool remove (const T& val) noexcept = 0;
};


template<typename T>
SetInterface<T>::~SetInterface() {
    //
}
