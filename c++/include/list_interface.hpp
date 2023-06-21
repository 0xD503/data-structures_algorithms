#ifndef __LIST_INTERFACE_HPP__
#define __LIST_INTERFACE_HPP__

#include <cstddef>


template<typename T>
class ListInterface {
    public:
        explicit ListInterface() = default;
        virtual ~ListInterface() = 0;

        inline size_t length () const noexcept      { return (_length); }

        inline bool front (T& val) const noexcept   { return (get(0, val)); }
        inline bool back (T& val) const noexcept {
            return (get(length() - 1, val));
        }

        virtual inline bool get (size_t index, T& dest) const noexcept = 0;
        virtual inline bool set (size_t index, const T& val) noexcept = 0;

        virtual inline bool swap (size_t index_1, size_t index_2) noexcept = 0;

        virtual inline bool insert (size_t index, const T& val) = 0;
        virtual inline bool remove (size_t index) = 0;

        inline bool append (const T& val) { return (insert(length(), val)); }
        inline bool prepend (const T& val) { return (insert(0, val)); }

        inline bool empty () const { return (length() == 0); }
        virtual inline bool clear () {
            bool done(true);

            while (not empty()) {
                if (not remove(0)) [[unlikely]] {
                    done = false;
                    break;
                }
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
