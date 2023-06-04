#ifndef __DEQUE_HPP__
#define __DEQUE_HPP__

#include "list_interface.hpp"


template<typename T>
class Deque : List<T> {
    public:
        ~Deque() = 0;

        inline bool addFirst (T val)    { return (add(0, val)); }
        inline bool removeFirst ()      { return (remove(0)); }
        inline bool addLast (T val)     { return (add(_length, val)); }
        inline bool removeLast ()       { return (remove(_length - 1)); }
};


template<typename T>
Deque<T>::~Deque() {
    //
}


#endif // __DEQUE_HPP__
