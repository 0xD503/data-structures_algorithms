#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include "list_interface.hpp"


template<typename T>
class LinkedList : public ListInterface<T> {
    public:
        struct Node {
            T value;
            Node *previous, *next;

            explicit Node(const T value_ = T(), Node *prev = nullptr,
                          Node *next_ = nullptr) :
                value(value_), previous(prev), next(next_) { }
        };

        LinkedList();
        LinkedList(const size_t length, const T fillValue);
        ~LinkedList();

        size_t size () const noexcept   { return (sizeof(T) * this->_length); }

        inline T first () const override    { return (get(0)); } /*_firstNode()->value*/
        inline T last () const override     { return (get(this->_length - 1)); }

        const T get (const size_t index) const override;
        T get (const size_t index) override;
        bool set (const size_t index, const T& value) noexcept override;

        bool add (const size_t index, const T& value) override;
        bool remove (const size_t index) override;

    protected:
        Node _rootNode;

        const Node *_getNode (size_t index) const;
        Node *_getNode (size_t index);

        // inline const Node *_firstNode () const  { return (_getNode(0)); }
        // inline Node *_firstNode ()              { return (_getNode(0)); }
        // inline const Node *_lastNode () const   { return (_getNode(this->_length - 1)); }
        // inline Node *_lastNode ()               { return (_getNode(this->_length - 1)); }





        // inline const Node *_firstNode () const {
        //     const Node *node = nullptr;

        //     if (this->_length > 0) {
        //         node = _rootNode.next;
        //     }

        //     return (node);
        // }
        // inline const Node *_lastNode () const {
        //     const Node *node(&_rootNode);

        //     while (node->next != nullptr) {
        //         node = node->next;
        //     }

        //     return (node);
        // }
};


#endif // __LINKED_LIST__
