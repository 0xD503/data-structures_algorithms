#include <iostream>

//#include <bag.hpp>
#include "dynamic_array.hpp"
#include "linked_list.hpp"
#include "deque.hpp"


using std::cout;
using std::clog;
using std::endl;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    int status = EXIT_FAILURE;

    // LinkedList<long> ll(7, 777);
    Deque<long> dq(7, 4);


    cout << "DQ len: " << dq.empty() << endl;
    cout << "DQ len: " << dq.length() << endl;
    cout << "DQ len: " << dq.clear() << endl;
    cout << "DQ len: " << dq.empty() << endl;
    cout << "DQ len: " << dq.length() << endl;

    // dq.addFront(1);
    // dq.addFront(2);
    // dq.addFront(3);
    // dq.addFront(4);
    // dq.addFront(5);
    // dq.addBack(0);
    // dq.addBack(-1);
    // dq.addBack(-2);
    // dq.addBack(-3);

    // cout << "DQ len: " << dq.length() << endl;

    // long val = dq.length();
    // for (size_t i(val); i > 0; i--) {
    //     dq.back(val);
    //     cout << "i: " << i << endl;
    //     cout << "back val: " << val << endl;
    //     dq.front(val);
    //     cout << "front val: " << val << endl;
    //     dq.removeBack();
    // }

    // for (size_t i(0); i < 900; i++) {
    //     dq.addFront(i);
    // }
    // for (size_t i(1); i < 100; i++) {
    //     dq.addBack(-i);
    // }
    // for (size_t i(0); i < 200; i++) {
    //     dq.removeFront();
    // }
    // for (size_t i(0); i < 200; i++) {
    //     dq.removeBack();
    // }
    // for (size_t i(0); i < 100; i++) {
    //     dq.removeFront();
    // }
    // for (size_t i(0); i < 499; i++) {
    //     dq.removeBack();
    // }

    // cout << "DQ empty: " << dq.empty() << endl;

    //Deque<long> dq_2{};
    // cout << "LL len: " << ll.length() << endl;
    // cout << "LL size: " << ll.size() << endl;
    // ll.clear();
    // cout << "LL len: " << ll.length() << endl;
    // cout << "LL size: " << ll.size() << endl;

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

    //for ()

    status = EXIT_SUCCESS;

    return (status);
}
