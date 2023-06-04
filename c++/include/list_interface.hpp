#ifndef __LIST_INTERFACE_HPP__
#define __LIST_INTERFACE_HPP__

#include <cstddef>


template<typename T>
class ListInterface {
    public:
        explicit ListInterface() : _length(0)   { }
        virtual ~ListInterface() = 0;

        inline size_t length () const noexcept      { return (_length); }

        virtual inline T first () const = 0;
        virtual inline T last () const = 0;

        virtual inline const T get (size_t index) const = 0;
        virtual inline T get (size_t index) = 0;
        virtual inline bool set (size_t index, const T& val) = 0;

        virtual inline bool add (size_t index, const T& val) = 0;
        virtual inline bool remove (size_t index) = 0;

        virtual inline bool empty () const { return (_length == 0); }
        virtual inline bool clear () {
            bool done(true);

            while (not empty()) {
                remove(0);
            }

            return (done);
        }

    protected:
        size_t _length;
        //size_t _capacity;
};


template<typename T>
ListInterface<T>::~ListInterface() {
    //
}


//template class ListInterface<int>;


#endif // __LIST_INTERFACE_HPP__
