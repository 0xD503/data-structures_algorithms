#pragma once

#include <cstddef>
#include "sorted_set_interface.hpp"
#include "static_array.hpp"
#include "forward_linked_list.hpp"


template<typename T, size_t maxLevels__ = 4>
class SkipList : public SortedSetInterface<T> {
    public:
        static_assert(maxLevels__ > 0, "number of levels for skip list should be >= 1");

        //SkipList()
        ~SkipList() override;

        inline size_t length () const noexcept override { return (levels__[baseLevelIndex__].length()); }

        inline bool clear () override {
            #warning "move out to implementation"
        }

        inline bool insert (const T& val) noexcept override {
            #warning "move out to implementation"
        }
        inline bool remove (const T& val) noexcept override {
            #warning "move out to implementation"
        }

        inline bool find (const T& val, T& dest) const noexcept override {
            #warning "move out to implementation"
        }

    private:
        static constexpr size_t baseLevelIndex__ = 0;
        StaticArray<ForwardLinkedList<T>, maxLevels__> levels__{};
};


template<typename T, size_t maxLevels__>
SkipList<T, maxLevels__>::~SkipList() {
    clear();
}


// template<typename T, size_t maxLevels__>
// size_t SkipList<T, maxLevels__>::length () const noexcept {
//     //
// }
