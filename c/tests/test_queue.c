#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

#include <queue.h>


void testSetup (void) {
    //
}

void testTeardown (void) {
    //
}


TestSuite(queue, .init = testSetup, .fini = testTeardown);


Test(queue, create) {
    Queue q;
    Queue_init(&q);
    cr_expect(Queue_length(&q) == 0);
    cr_expect(Queue_capacity(&q) == 0);

    Queue q_2;
    Queue_init_2(&q_2, 1999);
    cr_expect(Queue_length(&q_2) == 0);
    cr_expect(Queue_capacity(&q_2) == 1999);
}

Test(queue, size_manip) {
    //
}

Test(queue, add_elements) {
    Queue q;
    Queue_init(&q);
    cr_expect(Queue_length(&q) == 0);
    cr_expect(Queue_capacity(&q) == 0);
    Queue_add(&q, 'a');
    cr_expect(Queue_length(&q) == 1);
    cr_expect(Queue_capacity(&q) == 2);
    Queue_add(&q, 'b');
    cr_expect(Queue_length(&q) == 2, "wrong len");
    cr_expect(Queue_capacity(&q) == 2, "wrong cap");
    Queue_add(&q, 'c');
    cr_expect(Queue_length(&q) == 3);
    cr_expect(Queue_capacity(&q) == 6);
    Queue_add(&q, 'd');
    cr_expect(Queue_length(&q) == 4);
    cr_expect(Queue_capacity(&q) == 6);
    Queue_add(&q, 'e');
    cr_expect(Queue_length(&q) == 5);
    cr_expect(Queue_capacity(&q) == 6);
    Queue_add(&q, 'f');
    cr_expect(Queue_length(&q) == 6);
    cr_expect(Queue_capacity(&q) == 6);
    Queue_add(&q, 'g');
    cr_expect(Queue_length(&q) == 7);
    cr_expect(Queue_capacity(&q) == 14);

    Queue q_2;
    Queue_init_2(&q_2, 7);
    cr_expect(Queue_length(&q_2) == 0);
    cr_expect(Queue_capacity(&q_2) == 7);
    Queue_add(&q_2, 'e');
    Queue_add(&q_2, 'e');
    Queue_add(&q_2, 'e');
    Queue_add(&q_2, 'e');
    cr_expect(Queue_length(&q_2) == 4);
    cr_expect(Queue_capacity(&q_2) == 7);
    Queue_add(&q_2, 'e');
    Queue_add(&q_2, 'e');
    Queue_add(&q_2, 'e');
    Queue_add(&q_2, 'e');
    cr_expect(Queue_length(&q_2) == 8);
    cr_expect(Queue_capacity(&q_2) == 16);
}

Test(queue, remove_elements) {
    Queue q;
    Queue_init(&q);
    Queue_add(&q, 'a');
    Queue_add(&q, 'b');
    Queue_add(&q, 'c');
    Queue_add(&q, 'd');
    Queue_add(&q, 'e');
    Queue_add(&q, 'f');
    Queue_add(&q, 'g');
    Queue_add(&q, 'h');
    cr_expect(Queue_length(&q) == 8);
    cr_expect(Queue_capacity(&q) == 14);


}

Test(queue, access) {
    //
}
