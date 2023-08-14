#pragma once

#include "indexable_sequence_interface.hpp"

#include <algorithm>


template<typename T, const size_t length_>
class StaticArray: public IndexableSequenceInterface<T> {
    public:
        static_assert(length_ > 0, "length of static array should be > 0");

        StaticArray() = default;
        StaticArray(const T& fillValue);
        ~StaticArray() override = default;

        inline size_t length () const noexcept override { return (length_); }

        inline bool front (T& val) const noexcept override {
            bool success(false);
            if (length() > 0) {
                val = array_[0];
                success = true;
            }
            return (success);
        }
        inline bool back (T& val) const noexcept override {
            bool success(false);
            if (length() > 0) {
                val = array_[length() - 1];
                success = true;
            }
            return (success);
        }

        bool get (size_t index, T& dest) const noexcept override;
        bool set (size_t index, const T& val) noexcept override;

        bool swap (size_t index_1, size_t index_2) noexcept override;

        void fill (const T& val) noexcept;

        inline T *data () noexcept { return (&array_[0]); }
        inline const T *data () const noexcept { return (&array_[0]); }

        inline T& operator[] (size_t index) override { return array_[index]; }
        inline const T& operator[] (size_t index) const override { return array_[index]; }

    protected:
        T array_[length_]{};
};


template<typename T, size_t length_>
StaticArray<T, length_>::StaticArray(const T& fillValue) : StaticArray() {
    fill(fillValue);
}


template<typename T, size_t length_>
bool StaticArray<T, length_>::get (size_t index, T& dest) const noexcept {
    bool success(false);

    if (index < length()) {
        dest = array_[index];
        success = true;
    }

    return (success);
}

template<typename T, size_t length_>
bool StaticArray<T, length_>::set (size_t index, const T& val) noexcept {
    bool success(false);

    if (index < length()) {
        array_[index] = val;
        success = true;
    }

    return (success);
}


template<typename T, size_t length_>
bool StaticArray<T, length_>::swap (size_t index_1, size_t index_2) noexcept {
    bool success(false);

    if ((index_1 < length()) and (index_2 < length())) {
        T temp = array_[index_1];
        array_[index_1] = array_[index_2];
        array_[index_2] = temp;
        success = true;
    }

    return (success);
}


template<typename T, size_t length_>
void StaticArray<T, length_>::fill (const T& val) noexcept {
    std::fill_n(array_, length(), val);
}
