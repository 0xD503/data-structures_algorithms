#pragma once

#include "list_interface.hpp"

#include <utility>


template<typename T>
class DynamicArray : public ListInterface<T> {
    public:
        DynamicArray() = default;
        explicit DynamicArray(const size_t capacity);
        DynamicArray(const size_t length, const T& fillValue);
        DynamicArray(const DynamicArray& darr) = default;
        ~DynamicArray() override;

        inline DynamicArray& operator=(const DynamicArray& other) = default;

        /// memory management
        inline size_t capacity () const noexcept { return (_capacity); }
        inline size_t size () const noexcept override { return (sizeof(T) * _capacity); }
        bool resize (const size_t newSize);
        bool fit ();

        /// accessors
        inline T* data () noexcept { return (_array); }
        inline const T* data () const noexcept { return (_array); }

        /// getters/setters
        inline const T& operator[] (size_t index) const override { return (_array[index]); }
        inline T& operator[] (size_t index) override { return (_array[index]); }

        bool get (const size_t index, T& dest) const noexcept override;
        bool set (const size_t index, const T& val) noexcept override;

        /// modifiers
        bool swap (size_t index_1, size_t index_2) noexcept override;

        bool insert (const size_t index, const T& val) override;
        bool remove (const size_t index) override;

        bool clear () override;

    protected:
        T* _array {};
        size_t _capacity {};

    protected:
        // void _copyArray (T *dest, const T *src, const size_t index, const
        // size_t newLen, const T val);

    private:
        static constexpr size_t MEM_REALLOC_FACTOR = 2;
};
