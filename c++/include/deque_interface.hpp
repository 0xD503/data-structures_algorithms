#pragma once

#include "indexable_dynamic_sequence_interface.hpp"


template<typename T>
class DequeInterface : public IndexableDynamicSequenceInterface<T> {
    public:
        virtual ~DequeInterface() override = 0;

        virtual inline bool addFront (const T& val) = 0;
        virtual inline bool removeFront () = 0;
        virtual inline bool addBack (const T& val) = 0;
        virtual inline bool removeBack () = 0;

    protected:
        //
};


template<typename T>
DequeInterface<T>::~DequeInterface() {
    //
}
