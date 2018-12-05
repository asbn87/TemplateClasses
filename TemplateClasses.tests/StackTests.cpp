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