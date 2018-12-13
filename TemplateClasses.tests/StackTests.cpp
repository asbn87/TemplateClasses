#include "gtest/gtest.h"
#include "../TemplateClasses/Stack.h"

TEST(StackTests, WhenPushAddToTopOfStack)
{
	Stack<int>* stack = new Stack<int>();
	stack->Push(1);
	stack->Push(2);
	stack->Push(3);

	EXPECT_EQ(3, stack->Pop());
}

TEST(StackTests, SizeShouldReturnCorrectLength)
{
	Stack<int>* stack = new Stack<int>();
	stack->Push(1);
	stack->Push(2);
	stack->Push(3);
	stack->Push(4);
	stack->Pop();

	EXPECT_EQ(3, stack->Size());
}

TEST(StackTests, PopShouldReturnTopElementAndRemoveIt)
{
	Stack<int>* stack = new Stack<int>();
	stack->Push(1);
	stack->Push(2);
	stack->Push(3);

	EXPECT_EQ(3, stack->Pop());
	EXPECT_EQ(2, stack->Size());
}

TEST(StackTests, WhenMixingPopAndPushPopShouldStillReturnCorrectData)
{
	Stack<std::string>* stack = new Stack<std::string>();
	stack->Push("1");
	stack->Pop();
	stack->Push("2");
	stack->Push("3");
	stack->Pop();

	EXPECT_EQ("2", stack->Pop());
}

TEST(StackTests, StackShouldBeAbleToStoreAndReturnChars)
{
	Stack<char>* stack = new Stack<char>();
	stack->Push('a');
	stack->Push('b');

	EXPECT_EQ('b', stack->Pop());
}

TEST(StackTests, StackShouldBeAbleToStoreAndReturnInts)
{
	Stack<int>* stack = new Stack<int>();
	stack->Push(1);
	stack->Push(2);

	EXPECT_EQ(2, stack->Pop());
}

TEST(StackTests, StackShouldBeAbleToStoreStrings)
{
	Stack<std::string>* stack = new Stack<std::string>();
	stack->Push("This is string1");
	stack->Push("This is string2");

	EXPECT_EQ("This is string2", stack->Pop());
}

TEST(StackTests, PopShouldReturnNoDataWhenStackIsEmpty)
{
	Stack<int>* stack = new Stack<int>();

	EXPECT_EQ(NULL, stack->Pop());
}