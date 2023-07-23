#pragma once

#include "sequence_interface.hpp"


template<typename T>
class IndexableSequenceInterface : public SequenceInterface<T> {
    public:
        virtual ~IndexableSequenceInterface() override = 0;

        virtual inline bool get (size_t index, T& dest) const noexcept = 0;
        virtual inline bool set (size_t index, const T& val) noexcept = 0;
};


template<typename T>
IndexableSequenceInterface<T>::~IndexableSequenceInterface() {
    //
}
