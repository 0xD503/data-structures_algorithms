#pragma once

#include "dynamic_sequence_interface.hpp"
#include "indexable_sequence_interface.hpp"


template<typename T>
class DynamicIndexableSequenceInterface : public DynamicSequenceInterface<T>,
                                          public IndexableSequenceInterface<T> {
    public:
        virtual ~DynamicIndexableSequenceInterface() override = 0;
};


template<typename T>
DynamicIndexableSequenceInterface<T>::~DynamicIndexableSequenceInterface() {
    //
}
