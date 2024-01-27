#pragma once

#include "dynamic_container_interface.hpp"
#include "queue.hpp"


template<typename T>
class CircularBuffer : public DynamicContainerInterface<T> {
    public:
        CircularBuffer(const size_t maxLen, const bool overwritable = false);
        ~CircularBuffer() override { this->clear(); }

        inline size_t length () const noexcept override {
            return (queue_.length());
        }

        inline bool clear () override { return (queue_.clear()); }

        inline size_t maxLength () const noexcept { return (maxLength_); }
        inline bool setMaxLength (size_t maxLen) noexcept {
            bool status(false);
            if ((maxLen >= length()) and (maxLen != maxLength())) {
                maxLength_ = maxLen;
                status = true;
            }

            return (status);
        }
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
        Queue<T> queue_ {};
        bool overwritable_ { false };
};



template<typename T>
CircularBuffer<T>::CircularBuffer(const size_t maxLen,
                                  const bool overwritable) :
    DynamicContainerInterface<T>(),
    maxLength_(maxLen), queue_(maxLength_), overwritable_(overwritable) {
    //
}


template<typename T>
bool CircularBuffer<T>::get(T& dest) noexcept {
    bool success(queue_.front(dest));
    if (success) {
        queue_.remove();
    }

    return (success);
}

template<typename T>
bool CircularBuffer<T>::put(const T& val) noexcept {
    bool success(false);

    if (queue_.length() < maxLength()) {
        success = queue_.add(val);
    } else if (isOverwritable() and (maxLength() > 0)) {
        success = queue_.remove();
        success = success && queue_.add(val);
    }

    return (success);
}
