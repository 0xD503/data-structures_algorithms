#pragma once

#include "list_interface.hpp"


template<typename T>
class LinkedList : public ListInterface<T> {
    public:
        struct Node {
            T value{};
            Node *previous{}, *next{};

            explicit Node(const T value_ = T(), Node *prev = nullptr,
                          Node *next_ = nullptr) :
                value(value_), previous(prev), next(next_) { }
        };

        LinkedList() = default;
        LinkedList(const size_t length, const T& fillValue);
        ~LinkedList();

        size_t size () const noexcept   { return (sizeof(T) * this->length()); }

        bool get (const size_t index, T& dest) const noexcept override;
        bool set (const size_t index, const T& value) noexcept override;

        bool swap (size_t index_1, size_t index_2) noexcept override;

        bool insert (const size_t index, const T& value) override;
        bool remove (const size_t index) override;

    protected:
        Node _rootNode{T(), &_rootNode, &_rootNode};

        const Node *_getNode (size_t index) const noexcept;
        Node *_getNode (size_t index) noexcept;
};
