#pragma once

#include "container_interface.hpp"


template<typename T>
class SequenceInterface : public ContainerInterface<T> {
    public:
        virtual ~SequenceInterface() = 0;

        virtual inline bool front (T& val) const noexcept = 0;
        virtual inline bool back (T& val) const noexcept  = 0;
};


template<typename T>
SequenceInterface<T>::~SequenceInterface() {
    //
}
