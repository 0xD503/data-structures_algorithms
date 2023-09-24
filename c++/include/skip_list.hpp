#pragma once

#include "sorted_set_interface.hpp"
#include "static_array.hpp"
//#include "dynamic_array.hpp"
#include "forward_linked_list.hpp"


template<typename T, size_t maxLevels__ = 4>
class SkipList : public SortedSetInterface<T> {
    public:
        static_assert(maxLevels__ > 0, "number of levels for skip list should be >= 1");

        SkipList();
        ~SkipList() override;
        //~SkipList() override = default;

        inline size_t length () const noexcept override {
            return (levels__[baseLevelIndex__].length() - 1);
        }
        inline size_t getHeight () const noexcept { return (height__); }

        bool clear () override;

        bool insert (const T& val) noexcept override;
        bool remove (const T& val) noexcept override;

        bool find (const T& val, T& dest) const noexcept override;

    private:
        StaticArray<ForwardLinkedList<T>, maxLevels__> levels__{};
        //StaticArray<ForwardLinkedList<T *>, maxLevels__> levels__{};
        //StaticArray<DynamicArray<T *>, maxLevels__> levels__{};
        typename ForwardLinkedList<T>::Node sentinel__{};
        //const typename ForwardLinkedList<T>::Node *sentinel_p = &sentinel__;
        static constexpr size_t baseLevelIndex__{0};
        size_t height__{0};
};


template<typename T, size_t maxLevels_>
//SkipList<T, maxLevels_>::SkipList() : levels__() {
//SkipList<T, maxLevels_>::SkipList() : levels__(ForwardLinkedList<T>(0)) {
SkipList<T, maxLevels_>::SkipList() : levels__(ForwardLinkedList<T>(1)) {
    #warning "sentinel ???"
    //sentinel = ???
    // ForwardLinkedList<T> lst(1);
    // levels__.fill(lst);
}

template<typename T, size_t maxLevels__>
SkipList<T, maxLevels__>::~SkipList() {
    clear();
    #warning "sentinel ???"
}


template<typename T, size_t maxLevels__>
bool SkipList<T, maxLevels__>::clear () {
    bool status(false);

    #warning "sentinel ???"
    if (not this->empty()) {
    //if (not this->length() > 1) {
        status = true;
        for (size_t i(0); i < maxLevels__; i++) {
            status = levels__[i].clear() && status;
        }
    }

    return (status);
}


template<typename T, size_t maxLevels__>
bool SkipList<T, maxLevels__>::insert (const T& val) noexcept {
    //
}

template<typename T, size_t maxLevels__>
bool SkipList<T, maxLevels__>::remove (const T& val) noexcept {
    //
}


template<typename T, size_t maxLevels__>
bool SkipList<T, maxLevels__>::find (const T& val, T& dest) const noexcept {
    //
}
