#include "gtest/gtest.h"
#include "../TemplateClasses/Stack.h"

TEST(StackTests, WhenPushAddToTopOfStack)
{
	Stack<int> *intStack = new Stack<int>();
	intStack->Push(1);
	intStack->Push(2);
	intStack->Push(3);

	EXPECT_EQ(intStack->Pop(), 3);
}

TEST(StackTests, WhenPushStackShouldIncreaseInSize)
{
	Stack<int> *intStack = new Stack<int>();
	intStack->Push(1);
	intStack->Push(2);
	intStack->Push(3);
	int size = intStack->Size();
	intStack->Push(4);

	EXPECT_TRUE(intStack->Size() > size);
}

TEST(StackTests, WhenPopStackShouldDecreaseInSize)
{
	Stack<int> *intStack = new Stack<int>();
	intStack->Push(1);
	intStack->Push(2);
	intStack->Push(3);
	int size = intStack->Size();
	intStack->Pop();

	EXPECT_TRUE(intStack->Size() < size);
}

TEST(StackTests, WhenStackIsEmptySizeOfStackShouldBeZero)
{
	int size{ 10 };
	Stack<int> *intStack = new Stack<int>();
	if(intStack->Empty())
		size = intStack->Size();

	EXPECT_EQ(size, 0);
}

TEST(StackTests, WhenTopIsCalledTheLastAddedInStackShouldBeReturned)
{
	Stack<int> *intStack = new Stack<int>();
	intStack->Push(1);
	intStack->Push(2);
	intStack->Push(3);
	intStack->Push(4);
	intStack->Push(5);

	EXPECT_EQ(intStack->Top(), 5);
}