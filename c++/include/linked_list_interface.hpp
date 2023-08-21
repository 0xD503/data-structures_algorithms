#pragma once

#include "list_interface.hpp"


template<typename T>
class LinkedListInterface: public ListInterface<T> {
    public:
        virtual ~LinkedListInterface() override = 0;

        inline size_t size () const noexcept override { return (sizeof(T) * this->length()); }

        // inline bool swap (size_t index_1, size_t index_2) noexcept override {
        //     bool success(false);

        //     Node *n_1(getNode_(index_1));
        //     Node *n_2(getNode_(index_2));
        //     if ((n_1 != nullptr) && (n_2 != nullptr)) [[likely]] {
        //         T temp(n_1->value);
        //         n_1->value = n_2->value;
        //         n_2->value = temp;
        //         success = true;
        //     }

        //     return (success);
        // }
        inline bool clear () override {
            bool done(false);

            if (not this->empty()) {
                done = true;
                while (not this->empty()) {
                    if (not this->remove(0)) [[unlikely]] {
                    //if (not remove(length() - 1)) [[unlikely]] {
                        done = false;
                        break;
                    }
                }
            }

            return (done);
        }

    protected:
        // const Node *getNode_ (size_t index) const noexcept;
        // Node *getNode_ (size_t index) noexcept;
};


template<typename T>
LinkedListInterface<T>::~LinkedListInterface() {
    //
}
