#include "gtest/gtest.h"
#include "../TemplateClasses/DoubleLinkedList.h"

TEST(DoubleLinkedListTests, WhenPushFrontHeadShouldBeUpdated)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushFront(3);

	EXPECT_EQ(3, list->Get(0));
}

TEST(DoubleLinkedListTests, WhenGettingCorrectDataShouldBeReturned)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushFront(3);

	EXPECT_EQ(2, list->Get(1));
}
