#pragma once

#include "container_interface.hpp"
//#include "patterns/iterator.hpp"


template<typename T>
class SequenceInterface : virtual public ContainerInterface<T> {
    public:
        //using patterns::iterator::Iterator;

        virtual ~SequenceInterface() override = 0;

        virtual inline bool front (T& val) const noexcept = 0;
        virtual inline bool back (T& val) const noexcept = 0;

        // // virtual inline const patterns::iterator::Iterator<T> begin () const noexcept {
        // //     return patterns::iterator::begin<SequenceInterface, T>(*this);
        // // }
        // virtual inline patterns::iterator::Iterator<T> begin () noexcept {
        //     return patterns::iterator::begin<SequenceInterface<T>, T>(*this);
        // }
        // virtual inline patterns::iterator::Iterator<T> end () noexcept {
        //     return patterns::iterator::end<SequenceInterface<T>, T>(*this);
        // }
        // // virtual inline Iterator end () const noexcept = 0;
};


template<typename T>
SequenceInterface<T>::~SequenceInterface() {
    //
}
