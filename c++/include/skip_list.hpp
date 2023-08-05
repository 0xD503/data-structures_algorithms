#pragma once

#include "sorted_set_interface.hpp"
#include "dynamic_array.hpp"
#include "forward_linked_list.hpp"


template<typename T, size_t maxLevels_ = 6>
class SkipList : public SortedSetInterface<T> {
    public:
        //SkipList()
        ~SkipList() override;

    protected:
        //

    private:
        //
};
