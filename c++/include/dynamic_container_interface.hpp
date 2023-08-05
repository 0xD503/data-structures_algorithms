#pragma once

#include "container_interface.hpp"


template<typename T>
class DynamicContainerInterface : public ContainerInterface<T> {
    public:
        virtual ~DynamicContainerInterface() override = 0;

        inline bool empty () const { return (this->length() == 0); };
        virtual inline bool clear () = 0;
};


template<typename T>
DynamicContainerInterface<T>::~DynamicContainerInterface() {
    //
}
