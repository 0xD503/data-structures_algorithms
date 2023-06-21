#pragma once

#include "list_interface.hpp"

// #include <type_traits>
// #include <concepts>


template<typename T>
class DequeInterface {
//class Deque : protected ListInterface<T> {
    public:
        explicit DequeInterface() = default;
        ~DequeInterface() = 0;

        // static_assert(std::is_base_of(ListInterface, List), "not base of");
        // static_assert(std::derived_from(List, ListInterface), "not derived from");

        // inline bool addFront (const T& val) { return (this->prepend(val)); }
        // inline bool removeFront ()          { return (this->remove(0)); }
        // inline bool addBack (const T& val)  { return (this->append(val)); }
        // inline bool removeBack ()           { return (this->remove(this->length() - 1)); }

        // inline bool addFront (const T& val) { return (_list.prepend(val)); }
        // inline bool removeFront ()          { return (_list.remove(0)); }
        // inline bool addBack (const T& val)  { return (_list.append(val)); }
        // inline bool removeBack ()           { return (_list.remove(this->length() - 1)); }

        virtual inline size_t length () const noexcept = 0;

        virtual inline bool front (T& val) const noexcept = 0;
        virtual inline bool back (T& val) const noexcept  = 0;

        virtual inline bool addFront (const T& val) = 0;
        virtual inline bool removeFront ()          = 0;
        virtual inline bool addBack (const T& val)  = 0;
        virtual inline bool removeBack ()           = 0;

        virtual inline bool clear () = 0;

    protected:
        // List<T> _list{};
};


//template<class List, typename T>
template<typename T>
DequeInterface<T>::~DequeInterface() {
    //
}
