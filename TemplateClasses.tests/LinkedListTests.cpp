#include "gtest/gtest.h"
#include "../TemplateClasses/LinkedList.h"

TEST(LinkedListTests, WhenPushFrontHeadShouldBeUpdated)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushFront(3);
	
	EXPECT_EQ(3, list->Get(0));
}

TEST(LinkedListTests, WhenUsingGetCorrectDataShouldBeReturned)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushFront(3);

	EXPECT_EQ(2, list->Get(1));
}


TEST(LinkedListTests, WhenPushBackTailShouldBeUpdated)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushBack(1);
	list->PushBack(2);
	list->PushBack(3);
	
	EXPECT_EQ(3, list->Get(2));
}

TEST(LinkedListTests, ListShouldBeAbleToStoreAndReturnStrings)
{
	LinkedList<std::string>* list = new LinkedList<std::string>();
	list->PushFront("This is string1");
	list->PushFront("This is string2");
	list->PushFront("This is string3");

	EXPECT_EQ("This is string2", list->Get(1));
}

TEST(LinkedListTests, ListShouldBeAbleToStoreAndReturnInts)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushFront(10);
	list->PushFront(20);
	list->PushFront(30);

	EXPECT_EQ(20, list->Get(1));
}

TEST(LinkedListTests, ListShouldBeAbleToStoreAndReturnChars)
{
	LinkedList<char>* list = new LinkedList<char>();
	list->PushFront('a');
	list->PushFront('b');
	list->PushFront('c');

	EXPECT_EQ('b', list->Get(1));
}

TEST(LinkedListTests, WhenGetWithIndexOutOfRangeIsCalledNoDataShouldBeReturned)
{
	LinkedList<std::string>* list = new LinkedList<std::string>();
	list->PushBack("string1");
	list->PushBack("string2");
	list->PushBack("string3");
	list->PushBack("string4");

	EXPECT_EQ("" , list->Get(4));
}

TEST(LinkedListTests, SizeShouldReturnCorrectLength)
{
	LinkedList<int>* list = new LinkedList<int>();
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

TEST(LinkedListTests, PopFrontShouldReturnFirstElement)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushBack(3);
	list->PushBack(4);
	list->PushFront(5);

	EXPECT_EQ(5, list->PopFront());
}

TEST(LinkedListTests, PopBackShouldReturnLastElement)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushBack(3);
	list->PushFront(4);
	list->PushBack(5);

	EXPECT_EQ(5, list->PopBack());
}


TEST(LinkedListTests, WhenInsertingDataShouldBeStoredAtCorrectIndexAndIndexUpdated)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushBack(1);
	list->PushBack(2);
	list->PushBack(3);
	list->PushBack(4);
	list->Insert(2, 9);

	EXPECT_EQ(9, list->Get(2));
	EXPECT_EQ(3, list->Get(3));
}

TEST(LinkedListTests, WhenDeletingCorrectDataShouldBeDeletedAndIndexUpdated)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushBack(1);
	list->PushBack(2);
	list->PushBack(3);
	list->PushBack(4);
	list->Delete(2);

	EXPECT_EQ(4, list->Get(2));
}
