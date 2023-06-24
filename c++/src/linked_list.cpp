#include "linked_list.hpp"

#include <iostream>


using std::cout;
using std::cerr;
using std::clog;
using std::endl;

template<typename T>
LinkedList<T>::LinkedList(const size_t length, const T& fillValue):
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
bool LinkedList<T>::swap (size_t index_1, size_t index_2) noexcept {
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


// template<typename T>
// bool LinkedList<T>::insert (const size_t index, const T& value) {
//     bool success(false);
//     Node *newNode;
//     Node *prev, *next(_getNode(index));

//     if (next == nullptr) [[unlikely]] {
//         if (this->length() != index) {
//             goto end;
//         }
//         // else {
//         //     //
//         // }
//     }

//     try {
//         newNode = new Node(value);
//     } catch (std::bad_alloc& excpt) {
//         cerr << "Failed to allocate new list node, current length = "
//              << this->length() << endl;
//         goto end;
//     }

//     if (this->length() == 0) {
//         prev = &_rootNode;
//         next = &_rootNode;
//     }
//     else {
//         prev = next->previous;
//         //prev = next->previous;
//     }

//     newNode->previous = prev;
//     newNode->next = next;

//     newNode->previous->next = newNode;
//     newNode->next->previous = newNode;

//     this->_length++;
//     success = true;

// end:
//     return (success);
// }

// template<typename T>
// bool LinkedList<T>::remove (const size_t index) {
//     bool status(false);
//     Node *node, *prev, *next;

//     /// check if nothing to remove
//     if ((index >= this->_length) || (this->_length == 0)) {
//         goto end;
//     }

//     node = _getNode(index);
//     if (node != nullptr) {
//         prev = node->previous;
//         next = node->next;
//         try {
//             delete node;
//         } catch (...) {
//             cerr << "Failed to deallocate list node" << endl;
//             goto end;
//         }

//         prev->next = next;
//         if (index < (this->_length - 1)) {          /// if removing not the last node
//             next->previous = prev;
//         }
//         this->_length--;
//         status = true;
//     }

// end:
//     return (status);
// }


template<typename T>
bool LinkedList<T>::insert (const size_t index, const T& value) {
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
        next = &_rootNode;
    }
    else {
        next = _getNode(index);
        prev = next->previous;
    }

    try {
        newNode = new Node(value, prev, next);
    } catch (std::bad_alloc& excpt) {
        cerr << "Failed to allocate new list node, current length = "
             << this->_length << endl;
        goto end;
    }

    newNode->previous->next = newNode;      /// left neighbour updates
    if (index < this->length()) {
        newNode->next->previous = newNode;  /// right neighbour updates
    }
    else {
        _rootNode.previous = newNode;
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

    node = _getNode(index);
    if (node == nullptr) {
        cerr << "Failed to remove node with index " << index << endl;
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
    else {
        _rootNode.previous = prev;
    }
    this->_length--;
    status = true;

end:
    return (status);
}


// template<typename T>
// bool LinkedList<T>::insert (const size_t index, const T& value) {
//     bool success(false);
//     Node *newNode;
//     Node *prev, *next;

//     if (index > this->length()) [[unlikely]] {
//         goto end;
//     }
//     else if (index == this->length()) {
//         if (this->length() == 0) [[unlikely]] {  /// check if it is the first node to be added
//             prev = &_rootNode;
//         }
//         else [[likely]] {
//             prev = _getNode(index - 1);
//         }
//         next = nullptr;
//     }
//     else {
//         next = _getNode(index);
//         prev = next->previous;
//     }

//     try {
//         newNode = new Node(value, prev, next);
//     } catch (std::bad_alloc& excpt) {
//         cerr << "Failed to allocate new list node, current length = "
//              << this->_length << endl;
//         goto end;
//     }

//     newNode->previous->next = newNode;      /// left neighbour updates
//     if (index < this->length()) {
//         newNode->next->previous = newNode;  /// right neighbour updates
//     }

//     this->_length++;
//     success = true;

// end:
//     return (success);
// }

// template<typename T>
// bool LinkedList<T>::remove (const size_t index) {
//     bool status(false);
//     Node *node, *prev, *next;

//     /// check if nothing to remove
//     if ((index >= this->_length) || (this->_length == 0)) {
//         goto end;
//     }

//     try {
//         node = _getNode(index);
//     } catch (std::out_of_range& excpt) {
//         cerr << excpt.what() << endl;
//         goto end;
//     }
//     prev = node->previous;
//     next = node->next;
//     try {
//         delete node;
//     } catch (...) {
//         cerr << "Failed to deallocate list node" << endl;
//         goto end;
//     }

//     prev->next = next;
//     if (index < (this->_length - 1)) {          /// if removing not the last node
//         next->previous = prev;
//     }
//     this->_length--;
//     status = true;

// end:
//     return (status);
// }


template<typename T>
const LinkedList<T>::Node *LinkedList<T>::_getNode (size_t index) const noexcept {
    const Node *node(_rootNode.next);

    if (index < this->length()) [[likely]] {
        while (index > 0) {
            node = node->next;
            index--;
        }
    }
    else [[unlikely]] {
        node = nullptr;
    }

    return (node);
}

template<typename T>
LinkedList<T>::Node *LinkedList<T>::_getNode (size_t index) noexcept {
    Node *node(_rootNode.next);

    if (index < this->length()) [[likely]] {
        while (index > 0) {
            node = node->next;
            index--;
        }
    }
    else [[unlikely]] {
        node = nullptr;
    }

    return (node);
}


// template<typename T>
// LinkedList<T>::Node *LinkedList<T>::_getNode (size_t index) noexcept {
//     //const Node *node(_rootNode.next);
//     Node *node;
//     //size_t half = index / 2;

//     if (index < (this->length() / 2)) {
//         node = _rootNode.next;
//     //if (index <= (this->length() / 2)) {
//         while (index > 0) {
//             node = node->next;
//             index--;
//         }
//     }
//     else if (index < this->length()) {
//         node = _rootNode.previous;
//         while (index > 0) {
//             node = node->previous;
//             index--;
//         }
//     }
//     else [[unlikely]] {
//         node = nullptr;
//     }

//     return (node);
// }

// template<typename T>
// const LinkedList<T>::Node *LinkedList<T>::_getNode (size_t index) const noexcept {
//     //const Node *node(_rootNode.next);
//     const Node *node;
//     //size_t half = index / 2;

//     if (index < (this->length() / 2)) {
//         node = _rootNode.next;
//     //if (index <= (this->length() / 2)) {
//         while (index > 0) {
//             node = node->next;
//             index--;
//         }
//     }
//     else if (index < this->length()) {
//         node = _rootNode.previous;
//         while (index > 0) {
//             node = node->previous;
//             index--;
//         }
//     }
//     else [[unlikely]] {
//         node = nullptr;
//     }

//     return (node);
// }


///
template class LinkedList<long long>;
template class LinkedList<long>;
template class LinkedList<int>;
template class LinkedList<short>;
template class LinkedList<char>;
