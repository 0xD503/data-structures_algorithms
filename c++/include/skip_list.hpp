#pragma once

#include <cstddef>
#include "sorted_set_interface.hpp"
#include "static_array.hpp"
#include "forward_linked_list.hpp"
#include "algorithms/rng.hpp"


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

        bool find (const T& val, size_t& index) const noexcept override;

    private:
        struct Node {
            T val;
            Node *next[maxLevels__];
            size_t height;
        };

        StaticArray<ForwardLinkedList<T>, maxLevels__> levels__{};
        //StaticArray<DynamicArray<T *>, maxLevels__> levels__{};
        typename ForwardLinkedList<T>::Node sentinel__{};
        //const typename ForwardLinkedList<T>::Node *sentinel_p = &sentinel__;
        static constexpr size_t baseLevelIndex__{0};
        size_t height__{0};
        static RNG coinFlipper__;

        Node *findNode (const T& val) const noexcept;

        static bool flipCoin__ () noexcept;
};



template<typename T, size_t maxLevels_>
RNG SkipList<T, maxLevels_>::coinFlipper__(0, 1);



template<typename T, size_t maxLevels_>
SkipList<T, maxLevels_>::SkipList() : levels__(ForwardLinkedList<T>(1)) {
//SkipList<T, maxLevels_>::SkipList() : levels__(ForwardLinkedList<T>(1)), coinFlipper__(0, 1) {
    //#warning "sentinel ???"
    //sentinel = ???
    // ForwardLinkedList<T> lst(1);
    // levels__.fill(lst);
}

template<typename T, size_t maxLevels__>
SkipList<T, maxLevels__>::~SkipList() {
    clear();
    //#warning "sentinel ???"
}


template<typename T, size_t maxLevels__>
bool SkipList<T, maxLevels__>::clear () {
    bool status(false);

    //#warning "sentinel ???"
    if (not this->empty()) {
    //if (not this->length() > 1) {
        status = true;
        for (size_t i(0); i < height__; i++) {
            status = levels__[i].clear() && status;
        }
        height__ = 0;
    }

    return (status);
}


template<typename T, size_t maxLevels__>
bool SkipList<T, maxLevels__>::insert (const T& val) noexcept {
    //find in levels[baseLevelIndex__] proper position
    //if contains, stop, return false
    //otherwise flip a coin until it tails
    //on tail, fill each level at position with value
    ////assign next and prev pointers for each level
    //update height
    //return true
    bool inserted(false);
    size_t index;
    if (not find(val, index)) {
        size_t currLevelId(0);
        levels__[currLevelId].insert(index, val);
        while (currLevelId++ < maxLevels__) {
            if (not flipCoin__()) {
                break;
            }
            //size_t internalId;
            //levels__[currLevelId].find(val, internalId)
            //???
        }
        inserted = true;
    }

    return (inserted);
}

template<typename T, size_t maxLevels__>
bool SkipList<T, maxLevels__>::remove (const T& val) noexcept {
    //find in levels[baseLevelIndex__] proper position with value
    //if it doesn't contains, return false
    //otherewise remove the value from each level
    ////update pointers
    //update height
    //return true
    bool removed(false);
    size_t id;

    // if (find(val, id)) {
    //     //
    // }

    return (removed);
}


template<typename T, size_t maxLevels__>
bool SkipList<T, maxLevels__>::find (const T& val, size_t& index) const noexcept {
    //find in levels[baseLevelIndex__] proper position with value
    //if it doesn't contains, don't fill dest, return false
    //otherwise return true
    bool found(false);
    auto currH(height__);
    index = 0;

    while (currH > 0) {
        for (size_t i(0); i < levels__[currH].length(); i++) {
            if (levels__[currH][i] >= val) {
                index = i;
                if (levels__[currH][i] == val) {
                    found = true;
                }
                goto end;
            }
        }
    }

end:
    return (found);
}



template<typename T, size_t maxLevels__>
typename SkipList<T, maxLevels__>::Node *SkipList<T, maxLevels__>::findNode (const T& val) const noexcept {
    Node *node;

    //

    return (node);
}

template<typename T, size_t maxLevels__>
bool SkipList<T, maxLevels__>::flipCoin__ () noexcept {
    return (static_cast<bool>(coinFlipper__()));
}
