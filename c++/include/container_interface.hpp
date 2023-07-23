#pragma once

#include <cstddef>


template<typename T>
class ContainerInterface {
    public:
        virtual ~ContainerInterface() = 0;

        virtual inline size_t length () const noexcept = 0;

        inline bool empty () const { return (length() == 0); };
        virtual inline bool clear () = 0;
};


template<typename T>
ContainerInterface<T>::~ContainerInterface() {
    //
}
