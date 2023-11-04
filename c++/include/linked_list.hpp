#pragma once

#include "linked_list_interface.hpp"

#include <iostream>


template<typename T>
class LinkedList : public LinkedListInterface<T> {
    public:
        struct Node {
                T value{};
                Node *previous{}, *next{};

                explicit Node(const T value_ = T(), Node *prev = nullptr,
                              Node *next_ = nullptr) :
                    value(value_), previous(prev), next(next_) { }
        };

        LinkedList() = default;
        LinkedList(const size_t length, const T &fillValue);
        ~LinkedList() override;

        /// getters/setters
        const T& operator[] (size_t index) const override;
        T& operator[] (size_t index) override;

        bool get (const size_t index, T &dest) const noexcept override;
        bool set (const size_t index, const T &value) noexcept override;

        /// modifiers
        bool swap (size_t index_1, size_t index_2) noexcept override;

        bool insert (const size_t index, const T &value) override;
        bool remove (const size_t index) override;

    protected:
        Node _rootNode { T(), &_rootNode, &_rootNode };

        const Node *getNode_ (size_t index) const noexcept;
        Node *getNode_ (size_t index) noexcept;
};



template<typename T>
LinkedList<T>::LinkedList(const size_t length, const T &fillValue) :
    LinkedList<T>() {
    for (size_t i(0); i < length; i++) {
        insert(0, fillValue);
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
    this->clear();
}


template<typename T>
const T& LinkedList<T>::operator[] (size_t index) const {
    const Node *node;
    if (index < (this->length() / 2)) {
        node = _rootNode.next;
        while (index > 0) {
            node = node->next;
            index--;
        }
    }
    else {
        node = &_rootNode;
        while (index < this->length()) {
            node = node->previous;
            index++;
        }
    }

    return (node->value);
}

template<typename T>
T& LinkedList<T>::operator[] (size_t index) {
    Node *node;
    if (index < (this->length() / 2)) {
        node = _rootNode.next;
        while (index > 0) {
            node = node->next;
            index--;
        }
    }
    else {
        node = &_rootNode;
        while (index < this->length()) {
            node = node->previous;
            index++;
        }
    }

    return (node->value);
}


template<typename T>
bool LinkedList<T>::get(const size_t index, T &dest) const noexcept {
    bool success(false);

    const Node *node(getNode_(index));
    if (node != nullptr) {
        dest = node->value;
        success = true;
    }

    return (success);
}

template<typename T>
bool LinkedList<T>::set(const size_t index, const T &value) noexcept {
    bool success(false);

    Node *node(getNode_(index));
    if (node != nullptr) {
        node->value = value;
        success = true;
    }

    return (success);
}


template<typename T>
bool LinkedList<T>::swap(size_t index_1, size_t index_2) noexcept {
    bool success(false);

    Node *n_1(getNode_(index_1));
    Node *n_2(getNode_(index_2));
    if ((n_1 != nullptr) && (n_2 != nullptr)) [[likely]] {
        T temp(n_1->value);
        n_1->value = n_2->value;
        n_2->value = temp;
        success = true;
    }

    return (success);
}


template<typename T>
bool LinkedList<T>::insert(const size_t index, const T &value) {
    bool success(false);
    Node *newNode;
    Node *prev, *next;

    if (index == this->length()) {
        if (this->length() == 0)
            [[unlikely]] {  /// check if it is the first node to be added
            prev = &_rootNode;
        } else [[likely]] {
            prev = getNode_(index - 1);
        }
        next = &_rootNode;
    } else {
        next = getNode_(index);
        if (next == nullptr) {
            std::cerr << "Failed to add node at index " << index << std::endl;
            goto end;
        }
        prev = next->previous;
    }

    try {
        newNode = new Node(value, prev, next);
    } catch (std::bad_alloc &excpt) {
        std::cerr << "Failed to allocate new list node: " << excpt.what()
             << ", current length = " << this->length() << std::endl;
        goto end;
    }

    newNode->previous->next = newNode;  /// left neighbour updates
    if (index < this->length()) {
        newNode->next->previous = newNode;  /// right neighbour updates
    } else {
        _rootNode.previous = newNode;
    }

    this->_length++;
    success = true;

end:
    return (success);
}

template<typename T>
bool LinkedList<T>::remove(const size_t index) {
    bool success(false);
    Node *node, *prev, *next;

    node = getNode_(index);
    if (node == nullptr) {
        std::cerr << "Failed to remove node with index " << index << std::endl;
        goto end;
    }
    prev = node->previous;
    next = node->next;

    delete node;
    node = nullptr;

    prev->next = next;
    if (index < (this->_length - 1)) {  /// if removing not the last node
        next->previous = prev;
    } else {
        _rootNode.previous = prev;
    }
    this->_length--;
    success = true;

end:
    return (success);
}


template<typename T>
const typename LinkedList<T>::Node *LinkedList<T>::getNode_(size_t index) const noexcept {
    const Node *node;

    if (index < (this->length() / 2)) {
        node = _rootNode.next;
        while (index > 0) {
            node = node->next;
            index--;
        }
    }
    else if (index < this->length()) {
        node = &_rootNode;
        while (index < this->length()) {
            node = node->previous;
            index++;
        }
    }
    else [[unlikely]] {
        node = nullptr;
    }

    return (node);
}

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::getNode_(size_t index) noexcept {
    Node *node;

    if (index < (this->length() / 2)) {
        node = _rootNode.next;
        while (index > 0) {
            node = node->next;
            index--;
        }
    } else if (index < this->length()) {
        node = &_rootNode;
        while (index < this->length()) {
            node = node->previous;
            index++;
        }
    } else [[unlikely]] {
        node = nullptr;
    }

    return (node);
}
