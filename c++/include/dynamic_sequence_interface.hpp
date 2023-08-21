#pragma once

#include "dynamic_container_interface.hpp"
#include "sequence_interface.hpp"


template<typename T>
class DynamicSequenceInterface : public DynamicContainerInterface<T>,
                                 virtual public SequenceInterface<T> {
    public:
        virtual ~DynamicSequenceInterface() override = 0;

        // virtual inline bool front (T& val) const noexcept = 0;
        // virtual inline bool back (T& val) const noexcept = 0;
};


template<typename T>
DynamicSequenceInterface<T>::~DynamicSequenceInterface() {
    //
}
