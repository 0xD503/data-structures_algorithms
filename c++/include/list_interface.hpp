#pragma once

#include "indexable_dynamic_sequence_interface.hpp"


template<typename T>
class ListInterface : public DynamicIndexableSequenceInterface<T> {
    public:
        explicit ListInterface() = default;
        virtual ~ListInterface() override = 0;

        inline size_t length () const noexcept override { return (_length); }
        virtual inline size_t size () const noexcept = 0;

        inline bool front (T& val) const noexcept override {
            return (this->get(0, val));
        }
        inline bool back (T& val) const noexcept override {
            return (this->get(length() - 1, val));
        }

        virtual inline bool insert (size_t index, const T& val) = 0;
        virtual inline bool remove (size_t index) = 0;

        inline bool append (const T& val) { return (insert(length(), val)); }
        inline bool prepend (const T& val) { return (insert(0, val)); }

    protected:
        size_t _length {};
};


template<typename T>
ListInterface<T>::~ListInterface() {
    //
}


// template class ListInterface<int>;
