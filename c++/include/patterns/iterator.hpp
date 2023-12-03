#pragma once


namespace patterns {

template<typename T>
class Iterator {
    public:
        Iterator(T *ptr) : ptr_(ptr) {
            //
        }

        //operator=
        //operator++
        //operator--
        //operator!=
        //operator+=
        //operator-=
        //operator()
        //next()

        // /// prefix/postfix increment
        virtual inline Iterator<T>& operator++() noexcept = 0;
        inline Iterator<T>& operator++(T) noexcept {
            Iterator<T> old(*this);
            operator++();               /// call prefix op

            return *old;
        }

        // /// prefix/postfix decrement
        // inline Iterator<T>& operator--() {
        //     //NOT IMPLEMENTED

        //     return *this;
        // }
        // inline Iterator<T>& operator--(T) {
        //     Iterator<T> old(*this);
        //     operator--();               /// call prefix op

        //     return *old;
        // }
        //
        inline const T& operator*() const {
            return *ptr_;
        }

        /// equality/inequality
        virtual inline int operator<=>(const Iterator&) const noexcept = 0;
        //inline auto compare (const Iterator& lhs, const Iterator& rhs) {
        //    //
        //}
        // inline bool operator==(const Iterator& lhs, const Iterator& rhs) const {
        //     return compare(lhs, rhs) == 0;
        // }
        // inline bool operator!=(const Iterator<T>& lhs, const Iterator<T>& rhs) {
        //     return compare(lhs, rhs) != 0;
        // }

    protected:
        T *ptr_{nullptr};
};


template<typename SequenceType, typename T>
Iterator<T> begin (SequenceType& sequence) {
    //
}

template<typename SequenceType, typename T>
Iterator<T> end (SequenceType& sequence) {
    //
}

} /// namespace patterns::iterator
