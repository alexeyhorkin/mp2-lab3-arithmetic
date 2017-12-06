// тесты для стека

#include "stack.h"
#include <gtest.h>

class BigStack : public ::testing::Test {
protected:
	Stack<int> bf1;
	Stack<int> bf2;
	Stack<int> bf3;


public:
	BigStack() : bf1(50), bf2(100), bf3(0) {
		for(int i=0;i<50;i++)
		bf1.push(i);
		for (int i = 0; i<100; i++)
			bf2.push(i);
	}

	~BigStack() {}
};
class ParameterizedStack : public ::testing::TestWithParam<int>
{
protected:
	Stack<int> bf1;

public:
	ParameterizedStack() : bf1(GetParam())
	{
		for (int i = 0; i < GetParam(); i += 10)
			bf1.push(i);
	}

	~ParameterizedStack() {}
};



TEST_F(BigStack, Can_get_top)
{
	EXPECT_EQ(49, bf1.pop());
}

TEST_F(BigStack, Can_fully_push)
{
	bf1.push(100);
	EXPECT_EQ(100, bf1.pop());
}

TEST_F(BigStack, Can_not_get_if_empty)
{
	EXPECT_ANY_THROW(bf3.pop());
}

TEST_P(ParameterizedStack, can_create_bitfield)
{
	EXPECT_EQ(GetParam(), bf1.GetMaxSize());
}



INSTANTIATE_TEST_CASE_P(Instantiation1,
	ParameterizedStack,
	::testing::Values(20, 100, 1000));

int test_values[] = { 30, 300, 15, 500 };

INSTANTIATE_TEST_CASE_P(Instantiation2,
	ParameterizedStack,
	::testing::ValuesIn(test_values));

////////////////////////////////
























