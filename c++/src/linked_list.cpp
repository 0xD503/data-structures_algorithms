#include "linked_list.hpp"

#include <iostream>


using std::cout;
using std::cerr;
using std::clog;
using std::endl;

template<typename T>
LinkedList<T>::LinkedList(const size_t length, const T fillValue):
    LinkedList<T>() {

    for (size_t i(0); i < length; i++) {
        add(0, fillValue);
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
    this->clear();
}


template<typename T>
bool LinkedList<T>::get (const size_t index, T& dest) const noexcept {
    bool success(false);

    if (index < this->length()) {
        const Node *node = _getNode(index);
        if (node != nullptr) {
            dest = node->value;
            success = true;
        }
    }

    return (success);
}

template<typename T>
bool LinkedList<T>::set (const size_t index, const T& value) noexcept {
    bool status(false);

    if (index < this->_length) {
        _getNode(index)->value = value;
        status = true;
    }

    return (status);
}


template<typename T>
bool LinkedList<T>::add (const size_t index, const T& value) {
    bool success(false);
    Node *newNode;
    Node *prev, *next;

    if (index > this->length()) [[unlikely]] {
        goto end;
    }
    else if (index == this->length()) {
        if (this->length() == 0) [[unlikely]] {  /// check if it is the first node to be added
            prev = &_rootNode;
        }
        else [[likely]] {
            prev = _getNode(index - 1);
        }
        next = nullptr;
    }
    else {
        next = _getNode(index);
        prev = next->previous;
    }

    try {
        newNode = new Node(value, prev, next);
    } catch (std::bad_alloc& excpt) {
        cerr << "Failed to allocate new list node, length = " << this->_length
             << endl;
        goto end;
    }

    newNode->previous->next = newNode;      /// left neighbour updates
    if (index < this->length()) {
        newNode->next->previous = newNode;  /// right neighbour updates
    }

    this->_length++;
    success = true;

end:
    return (success);
}

template<typename T>
bool LinkedList<T>::remove (const size_t index) {
    bool status(false);
    Node *node, *prev, *next;

    /// check if nothing to remove
    if ((index >= this->_length) || (this->_length == 0)) {
        goto end;
    }

    try {
        node = _getNode(index);
    } catch (std::out_of_range& excpt) {
        cerr << excpt.what() << endl;
        goto end;
    }
    prev = node->previous;
    next = node->next;
    try {
        delete node;
    } catch (...) {
        cerr << "Failed to deallocate list node" << endl;
        goto end;
    }

    prev->next = next;
    if (index < (this->_length - 1)) {          /// if removing not the last node
        next->previous = prev;
    }
    this->_length--;
    status = true;

end:
    return (status);
}


template<typename T>
const LinkedList<T>::Node *LinkedList<T>::_getNode (size_t index) const {
    // const Node *node(_getNode(index));
    const Node *node(_rootNode.next);

    if (index < this->_length) [[likely]] {
        while (index > 0) {
            node = node->next;
            index--;
        }
    }
    else [[unlikely]] {
        node = nullptr;
        //throw std::out_of_range("Index is out of range (const)");
    }

    return (node);
}

template<typename T>
LinkedList<T>::Node *LinkedList<T>::_getNode (size_t index) {
    Node *node(_rootNode.next);

    if (index < this->length()) [[likely]] {
        while (index > 0) {
            node = node->next;
            index--;
        }
    }
    else [[unlikely]] {
        node = nullptr;
        //throw std::out_of_range("Index is out of range");
    }

    return (node);
}


///
//template class LinkedList<char>;
template class LinkedList<long>;
