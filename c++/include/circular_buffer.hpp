#pragma once

#include "queue.hpp"


// template<typename T, size_t maxLength_ = 0>
template<typename T>
class CircularBuffer : public ContainerInterface<T> {
    public:
        CircularBuffer(const size_t maxLen, const bool overwritable = false);
        ~CircularBuffer() override { this->clear(); }

        inline size_t length () const noexcept override {
            return (queue_.length());
        }

        inline bool clear () override { return (queue_.clear()); }

        inline size_t maxLength () const noexcept { return (maxLength_); }
        // inline void setMaxLength (size_t maxLen) noexcept { maxLength_ =
        // maxLen; }
        inline bool isFull () const noexcept {
            return (this->length() == maxLength());
        }

        inline bool isOverwritable () const noexcept { return (overwritable_); }
        inline void setOverwritability (bool overwritable) noexcept {
            overwritable_ = overwritable;
        }

        bool get (T& dest) noexcept;
        bool put (const T& val) noexcept;

    protected:
        size_t maxLength_ { 0 };
        // size_t head_{0}, tail_{0};
        Queue<T> queue_ {};
        bool overwritable_ { false };
};
