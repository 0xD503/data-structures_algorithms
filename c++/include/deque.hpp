#pragma once

#include "deque_interface.hpp"
#include "dynamic_array.hpp"


template<typename T>
class Deque : public DequeInterface<T> {
    public:
        Deque() = default;
        Deque(const size_t capacity);
        Deque(const size_t len, const T& fillValue);
        ~Deque();

        inline size_t length () const noexcept {
            return (_frontArray.length() + _backArray.length());
        }

        bool front (T& val) const noexcept override;
        bool back (T& val) const noexcept override;

        bool addFront (const T& val) override;
        bool removeFront ()          override;
        bool addBack (const T& val)  override;
        bool removeBack ()           override;

        inline bool empty () const override { return (length() == 0); }
        bool clear () override;

    protected:
        DynamicArray<T> _frontArray{};
        DynamicArray<T> _backArray{};
};
