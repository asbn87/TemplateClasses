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

TEST(DoubleLinkedListTests, WhenUsingGetCorrectDataShouldBeReturned)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushFront(3);

	EXPECT_EQ(2, list->Get(1));
}

TEST(DoubleLinkedListTests, WhenPushBackTailShouldBeUpdated)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1);
	list->PushBack(2);
	list->PushBack(3);

	EXPECT_EQ(3, list->Get(2));
}

TEST(DoubleLinkedListTests, ListShouldBeAbleToStoreAndReturnStrings)
{
	DoubleLinkedList<std::string>* list = new DoubleLinkedList<std::string>();
	list->PushBack("string1");
	list->PushBack("string2");
	list->PushBack("string3");
	list->PushBack("string4");

	EXPECT_EQ("string3", list->Get(2));
}

TEST(DoubleLinkedListTests, ListShouldBeAbleToStoreAndReturnInts)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1);
	list->PushBack(2);
	list->PushBack(3);
	list->PushBack(4);

	EXPECT_EQ(3, list->Get(2));
}

TEST(DoubleLinkedListTests, ListShouldBeAbleToStoreAndReturnChars)
{
	DoubleLinkedList<char>* list = new DoubleLinkedList<char>();
	list->PushBack('a');
	list->PushBack('b');
	list->PushBack('c');
	list->PushBack('d');

	EXPECT_EQ('c', list->Get(2));
}

TEST(DoubleLinkedListTests, WhenGetWithIndexOutOfRangeIsCalledNoDataShouldBeReturned)
{
	DoubleLinkedList<std::string>* list = new DoubleLinkedList<std::string>();
	list->PushBack("string1");
	list->PushBack("string2");
	list->PushBack("string3");
	list->PushBack("string4");

	EXPECT_EQ("", list->Get(4));
}

TEST(DoubleLinkedListTests, SizeShouldReturnCorrectLength)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1);
	list->PopBack();
	list->PushFront(2);
	list->PushBack(3);
	list->PushBack(4);
	list->PopFront();
	list->PushFront(5);
	list->PopBack();

	EXPECT_EQ(2, list->Size());
}

TEST(DoubleLinkedListTests, PopFrontShouldReturnFirstElement)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushBack(3);
	list->PushBack(4);
	list->PushFront(5);

	EXPECT_EQ(5, list->PopFront());
}

TEST(DoubleLinkedListTests, PopBackShouldReturnLastElement)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushBack(3);
	list->PushFront(4);
	list->PushBack(5);

	EXPECT_EQ(5, list->PopBack());
}

TEST(DoubleLinkedListTests, WhenInsertingDataShouldBeStoredAtCorrectIndexAndIndexUpdated)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1);
	list->PushBack(2);
	list->PushBack(3);
	list->PushBack(4);
	list->Insert(2, 9);

	EXPECT_EQ(9, list->Get(2));
	EXPECT_EQ(3, list->Get(3));
}

TEST(DoubleLinkedListTests, WhenDeletingCorrectDataShouldBeDeletedAndIndexUpdated)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1);
	list->PushBack(2);
	list->PushBack(3);
	list->PushBack(4);
	list->Delete(2);

	EXPECT_EQ(4, list->Get(2));
}
