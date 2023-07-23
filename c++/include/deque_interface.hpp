#pragma once

#include "sequence_interface.hpp"


template<typename T>
class DequeInterface : public SequenceInterface<T> {
    public:
        virtual ~DequeInterface() override = 0;


        virtual inline bool addFront (const T& val) = 0;
        virtual inline bool removeFront ()          = 0;
        virtual inline bool addBack (const T& val)  = 0;
        virtual inline bool removeBack ()           = 0;

    protected:
        //
};


template<typename T>
DequeInterface<T>::~DequeInterface() {
    //
}
