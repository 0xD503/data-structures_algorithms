
#pragma once

#include "linked_list_interface.hpp"

#include <exception>


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
        ForwardLinkedList(const size_t length, const T& fillValue = T());
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



template<typename T>
ForwardLinkedList<T>::ForwardLinkedList(const size_t length, const T& fillValue) :
    ForwardLinkedList<T>() {
    for (size_t i(0); i < length; i++) {
        insert(0, fillValue);
    }
}


template<typename T>
ForwardLinkedList<T>::~ForwardLinkedList() {
    this->clear();
}


template<typename T>
bool ForwardLinkedList<T>::get(const size_t index, T &dest) const noexcept {
    bool success(false);

    const Node *node(getNode_(index));
    if (node != nullptr) {
        dest = node->value;
        success = true;
    }

    return (success);
}

template<typename T>
bool ForwardLinkedList<T>::set(const size_t index, const T &value) noexcept {
    bool success(false);

    Node *node(getNode_(index));
    if (node != nullptr) {
        node->value = value;
        success = true;
    }

    return (success);
}


template<typename T>
bool ForwardLinkedList<T>::swap(size_t index_1, size_t index_2) noexcept {
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
bool ForwardLinkedList<T>::insert(const size_t index, const T &value) {
    bool success(false);
    Node *p(nullptr), *next, *newNode;

    if (index == 0) {
        next = head_;
    }
    else if (index <= this->length()) {
        p = getNode_(index - 1);
        next = p->next;
    }
    else {
        goto end;
    }

    try {
        newNode = new Node(value, next);
    } catch (std::bad_alloc &excpt) {
        goto end;
    }

    if (p != nullptr) {
        p->next = newNode;
    }
    else {
        head_ = newNode;
    }

    this->_length++;
    success = true;

end:
    return (success);
}

template<typename T>
bool ForwardLinkedList<T>::remove(const size_t index) {
    bool success(false);
    Node *node, *prev;

    if ((index < this->length())) [[likely]] {
        if (index > 0) {
            prev = getNode_(index - 1);
            node = prev->next;
            prev->next = node->next;
        }
        else {
            node = head_;
            head_ = head_->next;
        }

        delete node;
        node = nullptr;

        this->_length--;
        success = true;
    }

    return (success);
}


template<typename T>
const typename ForwardLinkedList<T>::Node *ForwardLinkedList<T>::getNode_(size_t index) const noexcept {
    const Node *node(nullptr);

    if (index < this->length()) {
        node = head_;
        while (index > 0) {
            node = node->next;
            index--;
        }
    }

    return (node);
}

template<typename T>
typename ForwardLinkedList<T>::Node *ForwardLinkedList<T>::getNode_(size_t index) noexcept {
    Node *node(nullptr);

    if (index < this->length()) {
        node = head_;
        while (index > 0) {
            node = node->next;
            index--;
        }
    }

    return (node);
}
