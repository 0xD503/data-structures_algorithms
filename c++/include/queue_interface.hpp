#pragma once

#include "sequence_interface.hpp"


template<typename T>
class QueueInterface : public SequenceInterface<T> {
    public:
        virtual ~QueueInterface() override = 0;

        virtual inline bool add (const T& val) = 0;
        virtual inline bool remove () = 0;
};


template<typename T>
QueueInterface<T>::~QueueInterface() {
    //
}