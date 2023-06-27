#include <criterion/criterion.h>

#include "stack.hpp"


void setUp () {
    //
}

void tearDown () {
    //
}


TestSuite(stack_if, .init = setUp, .fini = tearDown);


template<typename T>
void test_stack_if(StackInterface<T> *stack) {
    cr_assert_not_null(stack);
    T val(-4);

    cr_expect(stack->empty());
    cr_expect_eq(stack->length(), 0);

    cr_expect_not(stack->pop());
    cr_expect(stack->empty());
    cr_expect_eq(stack->length(), 0);
    cr_expect_not(stack->front(val));
    cr_expect_eq(val, -4);
    cr_expect_not(stack->back(val));
    cr_expect_eq(val, -4);
    cr_expect(stack->empty());
    cr_expect_eq(stack->length(), 0);
    cr_expect(stack->push(1));
    cr_expect_not(stack->empty());
    cr_expect_eq(stack->length(), 1);
    cr_expect(stack->front(val));
    cr_expect_eq(val, 1);
    cr_expect(stack->back(val));
    cr_expect_eq(val, 1);
    cr_expect(stack->push(2));
    cr_expect(stack->push(3));
    cr_expect(stack->push(4));
    cr_expect(stack->push(5));
    cr_expect(stack->push(6));
    cr_expect(stack->push(7));
    cr_expect_not(stack->empty());
    cr_expect_eq(stack->length(), 7);
    cr_expect(stack->front(val));
    cr_expect_eq(val, 1);
    cr_expect(stack->back(val));
    cr_expect_eq(val, 7);
    cr_expect(stack->pop());
    cr_expect_not(stack->empty());
    cr_expect_eq(stack->length(), 6);
    cr_expect(stack->front(val));
    cr_expect_eq(val, 1);
    cr_expect(stack->back(val));
    cr_expect_eq(val, 6);
    cr_expect(stack->pop());
    cr_expect(stack->pop());
    cr_expect(stack->pop());
    cr_expect_not(stack->empty());
    cr_expect_eq(stack->length(), 3);
    cr_expect(stack->front(val));
    cr_expect_eq(val, 1);
    cr_expect(stack->back(val));
    cr_expect_eq(val, 3);

    cr_expect_not(stack->empty());
    cr_expect_eq(stack->length(), 3);

    cr_expect(stack->pop());
    cr_expect_not(stack->empty());
    cr_expect_eq(stack->length(), 2);
    cr_expect(stack->front(val));
    cr_expect_eq(val, 1);
    cr_expect(stack->back(val));
    cr_expect_eq(val, 2);
    cr_expect(stack->pop());
    cr_expect_not(stack->empty());
    cr_expect_eq(stack->length(), 1);
    cr_expect(stack->front(val));
    cr_expect_eq(val, 1);
    cr_expect(stack->back(val));
    cr_expect_eq(val, 1);
    cr_expect(stack->pop());
    cr_expect_not(stack->pop());
    cr_expect(stack->empty());
    cr_expect_eq(stack->length(), 0);
    cr_expect_not(stack->front(val));
    cr_expect_eq(val, 1);
    cr_expect_not(stack->back(val));
    cr_expect_eq(val, 1);
}

template<typename T>
void test_non_empty_stack_if(StackInterface<T> *stack) {
    cr_assert_not_null(stack);
    T val(-4);

    cr_expect_not(stack->empty());
    cr_expect_eq(stack->length(), 9);

    cr_expect(stack->front(val));
    cr_expect_eq(val, 11);
    cr_expect(stack->back(val));
    cr_expect_eq(val, 11);
    cr_expect(stack->pop());
    cr_expect_eq(stack->length(), 8);
    cr_expect(stack->front(val));
    cr_expect_eq(val, 11);
    cr_expect(stack->back(val));
    cr_expect_eq(val, 11);
    cr_expect(stack->push(88));
    cr_expect(stack->push(88));
    cr_expect(stack->push(88));
    cr_expect_eq(stack->length(), 11);
    cr_expect(stack->front(val));
    cr_expect_eq(val, 11);
    cr_expect(stack->back(val));
    cr_expect_eq(val, 88);

    cr_expect(stack->pop());
    cr_expect(stack->pop());
    cr_expect_not(stack->empty());
    cr_expect_eq(stack->length(), 9);
    cr_expect(stack->front(val));
    cr_expect_eq(val, 11);
    cr_expect(stack->back(val));
    cr_expect_eq(val, 88);
    cr_expect(stack->pop());
    cr_expect_not(stack->empty());
    cr_expect_eq(stack->length(), 8);
    cr_expect(stack->front(val));
    cr_expect_eq(val, 11);
    cr_expect(stack->back(val));
    cr_expect_eq(val, 11);
    cr_expect(stack->pop());
    cr_expect(stack->pop());
    cr_expect(stack->pop());
    cr_expect(stack->pop());
    cr_expect(stack->pop());
    cr_expect(stack->pop());
    cr_expect(stack->pop());
    cr_expect_not(stack->empty());
    cr_expect_eq(stack->length(), 1);
    cr_expect(stack->front(val));
    cr_expect_eq(val, 11);
    cr_expect(stack->back(val));
    cr_expect_eq(val, 11);
    cr_expect(stack->pop());
    cr_expect(stack->empty());
    cr_expect_eq(stack->length(), 0);
    val = -1;
    cr_expect_not(stack->front(val));
    cr_expect_eq(val, -1);
    cr_expect_not(stack->back(val));
    cr_expect_eq(val, -1);
    cr_expect_not(stack->pop());

    cr_expect(stack->push(7));
    cr_expect(stack->push(8));
    cr_expect(stack->push(79));
    cr_expect_not(stack->empty());
    cr_expect_eq(stack->length(), 3);
    cr_expect(stack->front(val));
    cr_expect_eq(val, 7);
    cr_expect(stack->back(val));
    cr_expect_eq(val, 79);
}


Test(stack_if, stack_long) {
    Stack<long> stack;
    Stack<long> stack_2{};
    Stack<long> stack_3(5);
    Stack<long> stack_4(9, 11);

    test_stack_if<long>(&stack);
    test_stack_if<long>(&stack_2);
    test_stack_if<long>(&stack_3);
    test_non_empty_stack_if<long>(&stack_4);
}

Test(stack_if, stack_char) {
    Stack<char> stack;
    Stack<char> stack_2{};
    Stack<char> stack_3(5);
    Stack<char> stack_4(9, 11);

    test_stack_if<char>(&stack);
    test_stack_if<char>(&stack_2);
    test_stack_if<char>(&stack_3);
    test_non_empty_stack_if<char>(&stack_4);
}
