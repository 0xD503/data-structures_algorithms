#pragma once

#include "queue.hpp"


template<typename T, size_t maxLength_ = 0>
class CircularBuffer : ContainerInterface<T> {
    public:
        virtual ~CircularBuffer() override { clear(); }

        inline bool maxLength () const noexcept { return (maxLength_); }
        inline bool isFull () const noexcept {
            return (this->length() == maxLength());
        }

        bool get (T& dest);
        bool put (const T& val);

    protected:
        // size_t maxLength_{0};
        // size_t head_{0}, tail_{0};
        Queue<T> queue_;
        bool overwritable_ { false };
};
