#include "linked_list.hpp"

#include <iostream>


using std::cerr;
using std::clog;
using std::cout;
using std::endl;

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
bool LinkedList<T>::get(const size_t index, T &dest) const noexcept {
    bool success(false);

    const Node *node(_getNode(index));
    if (node != nullptr) {
        dest = node->value;
        success = true;
    }

    return (success);
}

template<typename T>
bool LinkedList<T>::set(const size_t index, const T &value) noexcept {
    bool status(false);

    Node *node(_getNode(index));
    if (node != nullptr) {
        node->value = value;
        status = true;
    }

    return (status);
}


template<typename T>
bool LinkedList<T>::swap(size_t index_1, size_t index_2) noexcept {
    bool success(false);

    Node *n_1(_getNode(index_1));
    Node *n_2(_getNode(index_2));
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
            prev = _getNode(index - 1);
        }
        next = &_rootNode;
    } else {
        next = _getNode(index);
        if (next == nullptr) {
            cerr << "Failed to add node at index " << index << endl;
            goto end;
        }
        prev = next->previous;
    }

    try {
        newNode = new Node(value, prev, next);
    } catch (std::bad_alloc &excpt) {
        cerr << "Failed to allocate new list node: " << excpt.what()
             << ", current length = " << this->_length << endl;
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
    bool status(false);
    Node *node, *prev, *next;

    node = _getNode(index);
    if (node == nullptr) {
        cerr << "Failed to remove node with index " << index << endl;
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
    status = true;

end:
    return (status);
}


template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::_getNode(size_t index) noexcept {
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

template<typename T>
const typename LinkedList<T>::Node *LinkedList<T>::_getNode(
    size_t index) const noexcept {
    const Node *node;

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


///
template class LinkedList<char>;
template class LinkedList<short>;
template class LinkedList<int>;
template class LinkedList<long>;
template class LinkedList<long long>;
