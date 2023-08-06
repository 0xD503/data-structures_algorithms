#pragma once

#include "sorted_set_interface.hpp"
#include "static_array.hpp"
#include "forward_linked_list.hpp"


template<typename T, size_t maxLevels_ = 6>
class SkipList : public SortedSetInterface<T> {
    public:
        //SkipList()
        ~SkipList() override;

    protected:
        //

    private:
        StaticArray<ForwardLinkedList<T>, maxLevels_> levels__{};
};
