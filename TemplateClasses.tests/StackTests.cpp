#include "gtest/gtest.h"
#include "../TemplateClasses/Stack.h"

TEST(StackTests, WhenPushAddToFirstInStack)
{
	int a{ 1 }, b{ 2 }, c{ 3 };
	Stack<int> *intStack = new Stack<int>();
	intStack->Push(a);
	intStack->Push(b);
	intStack->Push(c);

	EXPECT_EQ(intStack->Pop(), 3);
}

TEST(StackTests, WhenPushStackShouldIncreaseInSize)
{
	int size{ 0 };
	Stack<int> *intStack = new Stack<int>();
	intStack->Push(1);
	intStack->Push(2);
	intStack->Push(3);
	size = intStack->Size();
	intStack->Push(4);

	EXPECT_TRUE(intStack->Size() > size);
}

TEST(StackTests, WhenPopStackShouldDecreaseInSize)
{
	int size{ 0 };
	Stack<int> *intStack = new Stack<int>();
	intStack->Push(1);
	intStack->Push(2);
	intStack->Push(3);
	size = intStack->Size();
	intStack->Pop();
	EXPECT_TRUE(intStack->Size() < size);
}