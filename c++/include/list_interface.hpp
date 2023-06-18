#ifndef __LIST_INTERFACE_HPP__
#define __LIST_INTERFACE_HPP__

#include <cstddef>


template<typename T>
class ListInterface {
    public:
        explicit ListInterface() = default;
        virtual ~ListInterface() = 0;

        inline size_t length () const noexcept      { return (_length); }

        virtual inline T first () const            {
            T ret{};
            get(0, ret);

            return (ret);
        }
        virtual inline T last () const             {
            T ret{};
            get(_length - 1, ret);

            return (ret);
        }

        virtual inline bool get (size_t index, T& dest) const noexcept = 0;
        virtual inline bool set (size_t index, const T& val) noexcept = 0;

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
        size_t _length{};
};


template<typename T>
ListInterface<T>::~ListInterface() {
    //
}


//template class ListInterface<int>;


#endif // __LIST_INTERFACE_HPP__
