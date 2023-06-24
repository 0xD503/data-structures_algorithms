#include <iostream>

//#include <bag.hpp>
#include "dynamic_array.hpp"
#include "linked_list.hpp"
#include "deque.hpp"


using std::cout;
using std::clog;
using std::endl;

int main(int argc, char *argv[]) {
    int status = EXIT_FAILURE;

    LinkedList<long> ll(7, 777);
    Deque<long> dq;
    Deque<long> dq_2{};
    cout << "LL len: " << ll.length() << endl;
    cout << "LL size: " << ll.size() << endl;
    ll.clear();
    cout << "LL len: " << ll.length() << endl;
    cout << "LL size: " << ll.size() << endl;

    // DynamicArray<int> vec(5);

    // vec.insert(0, 7);
    // vec.insert(0, 6);
    // vec.insert(0, 5);
    // vec.insert(0, 3);
    // // cout << "BEFOREEEEEEEEEEEEEEEEEEEEEEEEEE" << endl;
    // // vec.set(1600, 800);
    // // cout << "AAFTEERRRRRRRRRRRRRRRRRRRRRRRRR" << endl;
    // cout << "first: " << vec.get(0) << endl;
    // cout << "s    : " << vec.get(1) << endl;
    // cout << "t    : " << vec.get(2) << endl;
    // cout << "f    : " << vec.get(3) << endl;

    status = EXIT_SUCCESS;

    return (status);
}
