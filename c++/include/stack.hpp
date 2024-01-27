#pragma once

#include "stack_interface.hpp"
#include "deque.hpp"



template<typename T>
class Stack : public StackInterface<T> {
    public:
        Stack() = default;
        Stack(const size_t capacity);
        Stack(const size_t len, const T& fillValue);
        ~Stack() override { clear(); }

        inline size_t length () const noexcept override {
            return (_deque.length());
        }

        inline bool clear () override { return (_deque.clear()); }

        inline bool push (const T& val) override {
            return (_deque.addBack(val));
        }
        inline bool pop () override { return (_deque.removeBack()); }

        inline bool top (T& val) const noexcept override {
            return (_deque.back(val));
        }

    protected:
        Deque<T> _deque {};
};



template<typename T>
Stack<T>::Stack(const size_t capacity) : _deque(capacity) {
    //
}

template<typename T>
Stack<T>::Stack(const size_t len, const T& fillValue) : _deque(len, fillValue) {
    //
}
