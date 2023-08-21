#pragma once

#include "dynamic_sequence_interface.hpp"
#include "indexable_sequence_interface.hpp"


template<typename T>
class DynamicIndexableSequenceInterface : public DynamicSequenceInterface<T>,
                                          public IndexableSequenceInterface<T> {
    public:
        virtual ~DynamicIndexableSequenceInterface() override = 0;

        // virtual inline bool get (size_t index, T& dest) const noexcept = 0;
        // virtual inline bool set (size_t index, const T& val) noexcept = 0;

        // virtual inline bool swap (size_t index_1, size_t index_2) noexcept = 0;
};


template<typename T>
DynamicIndexableSequenceInterface<T>::~DynamicIndexableSequenceInterface() {
    //
}
