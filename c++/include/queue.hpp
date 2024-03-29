#pragma once

#include "queue_interface.hpp"
#include "deque.hpp"


template<typename T>
class Queue : public QueueInterface<T> {
    public:
        Queue() = default;
        Queue(const size_t capacity);
        Queue(const size_t len, const T& fillValue);
        ~Queue() override { clear(); }

        inline size_t length () const noexcept override {
            return (_deque.length());
        }

        virtual inline bool clear () override { return (_deque.clear()); }

        inline bool front (T& val) const noexcept override {
            return (_deque.front(val));
        }
        inline bool back (T& val) const noexcept override {
            return (_deque.back(val));
        }

        bool add (const T& val) override;
        bool remove () override;

    protected:
        Deque<T> _deque {};
};



template<typename T>
Queue<T>::Queue(const size_t capacity) : _deque(capacity) {
    //
}

template<typename T>
Queue<T>::Queue(const size_t len, const T& fillValue) : _deque(len, fillValue) {
    //
}


template<typename T>
bool Queue<T>::add(const T& val) {
    return (_deque.addBack(val));
}

template<typename T>
bool Queue<T>::remove() {
    return (_deque.removeFront());
}
