#include <iostream>

//#include <bag.hpp>
#include "dynamic_array.hpp"
#include "linked_list.hpp"


using std::cout;
using std::clog;
using std::endl;

int main(int argc, char *argv[]) {
    int status = EXIT_FAILURE;

    LinkedList<long> ll(7, 777);
    cout << "LL len: " << ll.length() << endl;
    cout << "LL size: " << ll.size() << endl;
    ll.clear();
    cout << "LL len: " << ll.length() << endl;
    cout << "LL size: " << ll.size() << endl;

    // DynamicArray<int> vec(5);

    // vec.add(0, 7);
    // vec.add(0, 6);
    // vec.add(0, 5);
    // vec.add(0, 3);
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
