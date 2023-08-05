#include "forward_linked_list.hpp"

#include <exception>


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
            head_ = node->next;
        }
    }
    else [[unlikely]] {
        goto end;
    }

    delete node;
    node = nullptr;

    this->_length--;
    success = true;

end:
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


///
template class ForwardLinkedList<char>;
template class ForwardLinkedList<short>;
template class ForwardLinkedList<int>;
template class ForwardLinkedList<long>;
template class ForwardLinkedList<long long>;

// template class ForwardLinkedList<int8_t>;
// template class ForwardLinkedList<int16_t>;
// template class ForwardLinkedList<int32_t>;
// template class ForwardLinkedList<int64_t>;

// template class ForwardLinkedList<uint8_t>;
// template class ForwardLinkedList<uint16_t>;
// template class ForwardLinkedList<uint32_t>;
// template class ForwardLinkedList<uint64_t>;
