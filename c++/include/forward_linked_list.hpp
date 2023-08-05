#pragma once

#include "linked_list_interface.hpp"


template<typename T>
class ForwardLinkedList : public LinkedListInterface<T> {
    public:
        struct Node {
            T value{};
            Node *next{};

            explicit Node(const T val = T(), Node *nxt = nullptr) :
                value(val), next(nxt) { }
        };
        
        ForwardLinkedList() = default;
        ForwardLinkedList(const size_t length, const T& fillValue);
        ~ForwardLinkedList() override;

        bool get (const size_t index, T &dest) const noexcept override;
        bool set (const size_t index, const T &value) noexcept override;

        bool swap (size_t index_1, size_t index_2) noexcept override;

        bool insert (const size_t index, const T &value) override;
        bool remove (const size_t index) override;

    protected:
        Node *head_{nullptr};//, *tail_{nullptr};

        const Node *getNode_ (size_t index) const noexcept;
        Node *getNode_ (size_t index) noexcept;
};
