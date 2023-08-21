#pragma once

#include "sequence_interface.hpp"


template<typename T>
class IndexableSequenceInterface : virtual public SequenceInterface<T> {
    public:
        virtual ~IndexableSequenceInterface() override = 0;

        virtual inline bool get (size_t index, T& dest) const noexcept = 0;
        virtual inline bool set (size_t index, const T& val) noexcept = 0;

        virtual inline bool swap (size_t index_1, size_t index_2) noexcept = 0;

        virtual inline const T& operator[] (size_t index) const = 0;
        virtual inline T& operator[] (size_t index) = 0;
};


template<typename T>
IndexableSequenceInterface<T>::~IndexableSequenceInterface() {
    //
}
