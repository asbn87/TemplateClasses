#include "gtest/gtest.h"
#include "../TemplateClasses/Stack.h"

TEST(StackTests, WhenPushAddToTopOfStack)
{
	Stack<int> *stack = new Stack<int>();
	stack->Push(1);
	stack->Push(2);
	stack->Push(3);

	EXPECT_EQ(stack->Pop(), 3);
}

TEST(StackTests, WhenPushStackShouldIncreaseInSize)
{
	Stack<int> *stack = new Stack<int>();
	stack->Push(1);
	stack->Push(2);
	stack->Push(3);
	int size = stack->Size();
	stack->Push(4);

	EXPECT_TRUE(stack->Size() > size);
}

TEST(StackTests, WhenPopStackShouldDecreaseInSize)
{
	Stack<int> *stack = new Stack<int>();
	stack->Push(1);
	stack->Push(2);
	stack->Push(3);
	int size = stack->Size();
	stack->Pop();

	EXPECT_TRUE(stack->Size() < size);
}

TEST(StackTests, WhenPopCurrentTopShouldBeReturned)
{
	Stack<int> *stack = new Stack<int>();
	stack->Push(1);
	stack->Push(2);
	stack->Push(3);

	EXPECT_EQ(3, stack->Pop());
}

TEST(StackTests, WhenStackIsEmptySizeOfStackShouldBeZero)
{
	int size{ 10 };
	Stack<int> *stack = new Stack<int>();
	if(stack->Empty())
		size = stack->Size();

	EXPECT_EQ(size, 0);
}

TEST(StackTests, WhenTopIsCalledTheLastAddedInStackShouldBeReturned)
{
	Stack<int> *stack = new Stack<int>();
	stack->Push(1);
	stack->Push(2);
	stack->Push(3);
	stack->Push(4);
	stack->Push(5);

	EXPECT_EQ(stack->Top(), 5);
}

TEST(StackTests, WhenMixingPopAndPushTopShouldStillReturnCorrectData)
{
	Stack<std::string> *stack = new Stack<std::string>();
	stack->Push("1");	// 1
	stack->Pop();		//
	stack->Push("2");	// 2
	stack->Push("3");	// 2, 3
	stack->Pop();		// 2

	EXPECT_EQ("2", stack->Top());
}

TEST(StackTests, WhenMixingPopAndPushSizeShouldStillBeCorrect)
{
	Stack<int> *stack = new Stack<int>();
	stack->Push(1);	// 1
	stack->Pop();	//
	stack->Push(2);	// 2
	stack->Push(3);	// 2, 3
	stack->Pop();	// 2

	EXPECT_EQ(1, stack->Size());
}

TEST(StackTests, StackShouldBeAbleToStoreChars)
{
	Stack<char> *stack = new Stack<char>();

	EXPECT_NO_THROW(stack->Push('a'));
}

TEST(StackTests, StackShouldBeAbleToStoreInts)
{
	Stack<int> *stack = new Stack<int>();

	EXPECT_NO_THROW(stack->Push(1));
}

TEST(StackTests, StackShouldBeAbleToStoreStrings)
{
	Stack<std::string> *stack = new Stack<std::string>();

	EXPECT_NO_THROW(stack->Push("this is a string"));
}

TEST(StackTests, StackShouldBeAbleToStoreDoubles)
{
	Stack<double> *stack = new Stack<double>();

	EXPECT_NO_THROW(stack->Push(0.05));
}

