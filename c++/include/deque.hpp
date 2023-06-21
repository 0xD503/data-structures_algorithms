#pragma once

#include "deque_interface.hpp"
#include "dynamic_array.hpp"


template<typename T>
class Deque : public DequeInterface<T> {
    public:
        Deque() = default;
        ~Deque();

        inline size_t length () const noexcept {
            return (_frontArray.length() + _backArray.length());
        }

        inline bool front (T& val) const noexcept override {
            return (_frontArray.back(val));
        }
        inline bool back (T& val) const noexcept override {
            return (_backArray.back());
        }

        bool addFront (const T& val) override;
        bool removeFront ()          override;
        bool addBack (const T& val)  override;
        bool removeBack ()           override;

        bool clear () override;

    protected:
        DynamicArray<T> _frontArray{};
        DynamicArray<T> _backArray{};
};
