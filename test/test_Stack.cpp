#include "Stack.h"
#include <gtest.h>

TEST(Stack, can_create_Stack) {
	ASSERT_NO_THROW(Stack<int> st);
}
TEST(Stack, can_push) {
	Stack<int> st;
	ASSERT_NO_THROW(st.pushS(1));
}
TEST(Stack, getSize_work_correctly) {
	Stack<int> st;
	st.pushS(1);
	st.pushS(2);
	st.pushS(3);
	EXPECT_EQ(3, st.sizeS());
}
TEST(Stack, empty_work) {
	Stack<int> st1;
	ASSERT_NO_THROW(st1.emptyS());
}
TEST(Stack, empty_work_correctly_on_empty_Stack) {
	Stack<int> st1;
	EXPECT_EQ(1, st1.emptyS());
}
TEST(Stack, empty_work_correctly_on_no_empty_Stack) {
	Stack<int> st1;
	st1.pushS(1);
	EXPECT_EQ(0, st1.emptyS());
}
TEST(Stack, top_work_correctly) {
	Stack<int> st;
	st.pushS(1);
	EXPECT_EQ(1, st.topS());
}
TEST(Stack, can_pop_no_empty_Stack) {
	Stack<int> st;
	st.pushS(1);
	ASSERT_NO_THROW(st.popS());
}
TEST(Stack, cant_pop_empty_Stack) {
	Stack<int> st;
	ASSERT_ANY_THROW(st.popS());
}