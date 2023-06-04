#ifndef USET_INTERFACE_H_
#define USET_INTERFACE_H_

#include <cstddef>


template<typename T>
class UnsortedSetI {
    public:
        explicit UnsortedSetI() : _length(0) { }
        virtual ~UnsortedSetI() = 0;

        inline size_t length () const       { return (_length); }

        inline virtual bool add (const T& elem) = 0;
        inline virtual bool remove (const T& i) = 0;

        inline virtual bool find (const T& elem) = 0;

    protected:
        size_t _length;
};


#endif // USET_INTERFACE_H_
