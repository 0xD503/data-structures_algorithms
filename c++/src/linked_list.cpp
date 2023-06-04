#include "linked_list.hpp"

#include <iostream>


using std::cout;
using std::cerr;
using std::clog;
using std::endl;

template<typename T>
LinkedList<T>::LinkedList():
    ListInterface<T>(), _rootNode() {
    //
}

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
const T LinkedList<T>::get (const size_t index) const {
    T val = T();

    try {
        const Node *node = _getNode(index);
        if (node != nullptr) {
            val = node->value;
        }
    } catch (std::out_of_range& excpt) {
        cerr << excpt.what() << endl;
    }

    return (val);
}

template<typename T>
T LinkedList<T>::get (const size_t index) {
    T val = T();
    Node *node;

    try {
        node = _getNode(index);
    } catch (std::out_of_range& excpt) {
        cerr << excpt.what() << endl;
        goto end;
    }
    if (node != nullptr) {
        val = node->value;
    }

end:
    return (val);
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
    Node *newNode(nullptr);
    Node *prev, *next;

    if (index > this->_length) {
        goto end;
    }
    try {
        next = _getNode(index);
    } catch (std::out_of_range& excpt) {
        next = nullptr;
        cerr << excpt.what() << endl;
    }

    if (this->_length == 0) [[unlikely]] {  /// check if it is the first node to be added
        prev = &_rootNode;
    }
    else if (next != nullptr) {
        prev = next->previous;
    }
    else {
        goto end;
    }

    try {
        newNode = new Node(value, prev, next);
    } catch (std::bad_alloc& excpt) {
        cerr << "Failed to allocate new list node, length = " << this->_length
             << endl;
        goto end;
    }

    newNode->previous = prev;
    newNode->previous->next = newNode;      /// left neighbour updates
    if (index < this->_length) [[likely]] {
        newNode->next->previous = newNode;  /// right neighbour updates
        //newNode->next->previous = next;  /// right neighbour updates
    }
    // else [[unlikely]] {
    //     newNode->next = nullptr;
    // }
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
    const Node *node(_rootNode.next);

    if (index < this->_length) [[likely]] {
        while (index > 0) {
            node = node->next;
            index--;
            // if (node == nullptr) {
            //     break;
            // }
        }
    }
    else [[unlikely]] {
        node = nullptr;
        throw std::out_of_range("Index is out of range");
    }

    return (node);
}

template<typename T>
LinkedList<T>::Node *LinkedList<T>::_getNode (size_t index) {
    Node *node(_rootNode.next);

    if (index < this->_length) [[likely]] {
        while (index > 0) {
            node = node->next;
            index--;
            // if (node == nullptr) {
            //     break;
            // }
        }
    }
    else [[unlikely]] {
        node = nullptr;
        throw std::out_of_range("Index is out of range");
    }

    return (node);
}


///
//template class LinkedList<char>;
template class LinkedList<long>;
