#include "Queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue) {
	ASSERT_NO_THROW(Queue<int> q);
}
TEST(Queue, can_push_empty_queue) {
	Queue<int> q;
	ASSERT_NO_THROW(q.pushQ(1));
}
TEST(Queue, can_push_not_field_queue) {
	Queue<int> q;
	q.pushQ(1);
	ASSERT_NO_THROW(q.pushQ(2));
}
TEST(Queue, can_push_on_zero_position) {
	Queue<int> q;
	q.pushQ(1);
	q.popQ();
	q.pushQ(1);
	q.pushQ(2);
	ASSERT_NO_THROW(q.pushQ(3));
}
TEST(Queue, can_push_after_resize) {
	Queue<int> q;
	q.pushQ(1);
	q.pushQ(2);
	q.pushQ(3);
	ASSERT_NO_THROW(q.pushQ(4));
}
TEST(Queue, can_pop_no_empty_queue) {
	Queue<int> q;
	q.pushQ(1);
	ASSERT_NO_THROW(q.popQ());
}
TEST(Queue, cant_pop_empty_queue) {
	Queue<int> q;
	ASSERT_ANY_THROW(q.popQ());
}
TEST(Queue, empty_work) {
	Queue<int> q;
	ASSERT_NO_THROW(q.emptyQ());
}
TEST(Queue, empty_work_correctly_on_empty_queue) {
	Queue<int> q;
	EXPECT_EQ(1, q.emptyQ());
}
TEST(Queue, empty_work_correctly_on_no_empty_queue) {
	Queue<int> q;
	q.pushQ(1);
	EXPECT_EQ(0, q.emptyQ());
}
TEST(Queue, getSize_work_correctly) {
	Queue<int> q;
	q.pushQ(1);
	q.pushQ(2);
	q.pushQ(3);
	EXPECT_EQ(3, q.sizeQ());
}
TEST(Queue, top_work_correctly) {
	Queue<int> q;
	q.pushQ(1);
	EXPECT_EQ(1, q.topQ());
}