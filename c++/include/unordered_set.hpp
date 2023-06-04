// #ifndef __UNORDERED_SET_HPP__
// #define __UNORDERED_SET_HPP__

// #include "uset_interface.hpp"

// #include <cstdint>


// template<typename T>
// class UnorderedSet : UnsortedSetI<T> {
//     public:
//         UnorderedSet();
//         explicit UnorderedSet(size_t cap);
//         ~UnorderedSet();

//         inline size_t capacity () const   { return (_capacity); }
//         inline size_t size () const       { return (sizeof(T) * _capacity); }

//         bool add (const T& elem) override;
//         bool remove (const T& i) override;

//         bool find (const T& elem) override;

//     protected:
//         virtual uint32_t hash (const T& elem) const;

//     protected:
//         T *_buckets;
//         size_t _capacity;
// };


// #endif // __UNORDERED_SET_HPP__
