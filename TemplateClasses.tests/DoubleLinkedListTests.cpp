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

TEST(DoubleLinkedListTests, HeadAndTailShouldNotBeTheSameWhenPushBackAndListSizeLargerThan1)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1);
	list->PushBack(2);

	EXPECT_TRUE(list->Get(0) != list->Get(1));
}

TEST(DoubleLinkedListTests, HeadAndTailShouldNotBeTheSameWhenPushFrontAndListSizeLargerThan1)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);

	EXPECT_TRUE(list->Get(0) != list->Get(1));
}

TEST(DoubleLinkedListTests, ListShouldBeAbleToStoreStrings)
{
	DoubleLinkedList<std::string>* list = new DoubleLinkedList<std::string>();

	EXPECT_NO_THROW(list->PushFront("This is a string"));
}

TEST(DoubleLinkedListTests, ListShouldBeAbleToStoreInts)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();

	EXPECT_NO_THROW(list->PushFront(1));
}

TEST(DoubleLinkedListTests, ListShouldBeAbleToStoreChars)
{
	DoubleLinkedList<char>* list = new DoubleLinkedList<char>();

	EXPECT_NO_THROW(list->PushFront('a'));
}

TEST(DoubleLinkedListTests, ListShouldBeAbleToStoreDoubles)
{
	DoubleLinkedList<double>* list = new DoubleLinkedList<double>();

	EXPECT_NO_THROW(list->PushFront(0.05));
}

TEST(DoubleLinkedListTests, WhenGetWithIndexOutOfRangeIsCalledNullShouldBeReturned)
{
	DoubleLinkedList<std::string>* list = new DoubleLinkedList<std::string>();
	list->PushBack("string1");
	list->PushBack("string2");
	list->PushBack("string3");
	list->PushBack("string4");

	EXPECT_EQ("", list->Get(4));
}

TEST(DoubleLinkedListTests, GetIndexShouldReturnCorrectData)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1); // 0
	list->PushBack(2); // 1
	list->PushBack(3); // 2
	list->PushBack(4); // 3

	EXPECT_EQ(2, list->Get(1));
}

TEST(DoubleLinkedListTests, WhenMixingPushAndPopSizeShouldBeCorrect)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1);	// 1
	list->PopBack();	// 0
	list->PushFront(2);	// 1
	list->PushBack(3);	// 2
	list->PushBack(4);	// 3
	list->PopFront();	// 2
	list->PushFront(5); // 3
	list->PopBack();	// 2

	EXPECT_EQ(2, list->Size());
}

TEST(DoubleLinkedListTests, WhenMixingPushAndPopHeadShouldBeCorrect)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1);	// 1
	list->PopBack();	//
	list->PushFront(2); // 2
	list->PushBack(3);	// 2, 3
	list->PushBack(4);	// 2, 3, 4
	list->PopFront();	// 3, 4
	list->PushFront(5); // 5, 3, 4
	list->PopBack();	// 5, 3

	EXPECT_EQ(5, list->Get(0));
}

TEST(DoubleLinkedListTests, WhenMixingPushAndPopTailShouldBeCorrect)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1);	// 1
	list->PushFront(2); // 2, 1
	list->PushBack(3);	// 2, 1, 3
	list->PopFront();	// 1, 3
	list->PushFront(4); // 4, 1, 3
	list->PopBack();	// 4, 1
	list->PushBack(5);	// 4, 1, 5

	EXPECT_EQ(5, list->Get(list->Size() - 1));
}

TEST(DoubleLinkedListTests, WhenInsertingSizeShouldBeUpdated)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1); // 1
	list->PushBack(2); // 2
	list->PushBack(3); // 3
	list->PushBack(4); // 4
	list->Insert(2, 9); // 5

	EXPECT_EQ(5, list->Size());
}

TEST(DoubleLinkedListTests, WhenInsertingDataShouldBeStoredAtCorrectIndex)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1); // 0
	list->PushBack(2); // 1
	list->PushBack(3); // 2 -> 3
	list->PushBack(4); // 3 -> 4
	list->Insert(2, 9); // 2

	EXPECT_EQ(9, list->Get(2));
}

TEST(DoubleLinkedListTests, WhenDeletingSizeShouldBeUpdated)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1); // 1
	list->PushBack(2); // 2
	list->PushBack(3); // 3
	list->PushBack(4); // 4
	list->Delete(2); // 3

	EXPECT_EQ(3, list->Size());
}

TEST(DoubleLinkedListTests, WhenDeletingCorectDataShouldBeDeleted)
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>();
	list->PushBack(1);
	list->PushBack(2);
	list->PushBack(3);
	list->PushBack(4);
	list->Delete(2);

	EXPECT_EQ(4, list->Get(2));
}
