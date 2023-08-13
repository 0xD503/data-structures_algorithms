#pragma once

#include "sorted_set_interface.hpp"
#include "static_array.hpp"
#include "forward_linked_list.hpp"


template<typename T, size_t maxLevels_ = 6>
class SkipList : public SortedSetInterface<T> {
    public:
        //SkipList()
        ~SkipList() override;

        //inline size_t length () const noexcept { return levels__[baseLevelIndex_].length(); }
        inline size_t length () const noexcept {
            #warning "move out to implementation"
            //return levels__[baseLevelIndex_].length();
            //return levels__.get(baseLevelIndex_).length();
        }

        inline bool clear () {
            #warning "move out to implementation"
        }

        inline bool insert (const T& val) noexcept {
            #warning "move out to implementation"
        }
        inline bool remove (const T& val) noexcept {
            #warning "move out to implementation"
        }

        inline bool find (const T& val, T& dest) const noexcept {
            #warning "move out to implementation"
        }

    protected:
        static constexpr size_t baseLevelIndex_ = 0;

    private:
        StaticArray<ForwardLinkedList<T>, maxLevels_> levels__{};
};


template<typename T, size_t maxLevels_>
SkipList<T, maxLevels_>::~SkipList() {
    clear();
}
