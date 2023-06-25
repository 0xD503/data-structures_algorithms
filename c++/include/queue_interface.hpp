#pragma once

#include "sequence_interface.hpp"


template<typename T>
class QueueInterface : public SequenceInterface<T> {
    public:
        virtual ~QueueInterface() = 0;

        virtual inline bool add (const T& val) = 0;
        virtual inline bool remove (T& val) = 0;
};


template<typename T>
QueueInterface<T>::~QueueInterface() {
    //
}
