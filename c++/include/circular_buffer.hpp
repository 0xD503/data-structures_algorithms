#pragma once

//


template<typename T, size_t maxLength_ = 0>
class CircularBuffer {
    public:
        //

        inline bool maxLength () const noexcept { return (maxLength_); }
        inline bool isFull () const noexcept { return (this->length() == maxLength()); }

    protected:
        //constexpr size_t maxLength_{0};
        //size_t head_{0}, tail_{0};
        bool overwritable_{false};
};
