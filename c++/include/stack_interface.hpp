#pragma once

//#include "dynamic_sequence_interface.hpp"
#include "dynamic_container_interface.hpp"


template<typename T>
//class StackInterface : public DynamicSequenceInterface<T> {
class StackInterface : public DynamicContainerInterface<T> {
    public:
        virtual ~StackInterface() override = 0;

        virtual inline bool push (const T& val) = 0;
        virtual inline bool pop () = 0;

        virtual inline bool top (T& val) const noexcept = 0;
};


template<typename T>
StackInterface<T>::~StackInterface() {
    //
}
