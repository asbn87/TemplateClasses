#include "gtest/gtest.h"
#include "../TemplateClasses/LinkedList.h"


TEST(LinkedListTests, WhenPushFrontHeadShouldBeUpdated)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushFront(3);
	
	EXPECT_EQ(3, list->getData(0));
}

TEST(LinkedListTests, WhenPushFrontHeadsNextShouldBeOldHead)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushFront(3);

	EXPECT_EQ(2, list->getData(1));
}

TEST(LinkedListTests, WhenPushBackTailShouldBeUpdated)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushBack(1);
	list->PushBack(2);
	list->PushBack(3);
	
	EXPECT_EQ(3, list->getData(2));
}

TEST(LinkedListTests, HeadAndTailShouldNotBeTheSameWhenPushBack)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushBack(1);
	list->PushBack(2);
	list->PushBack(3);

	EXPECT_TRUE(list->getData(0) != list->getData(2));
}

TEST(LinkedListTests, HeadAndTailShouldNotBeTheSameWhenPushFront)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushFront(3);

	EXPECT_TRUE(list->getData(0) != list->getData(2));
}

TEST(LinkedListTests, ListShouldBeAbleToStoreStrings)
{
	LinkedList<std::string>* list = new LinkedList<std::string>();
	
	EXPECT_NO_THROW(list->PushFront("This is a string"));
}

TEST(LinkedListTests, ListShouldBeAbleToStoreInts)
{
	LinkedList<int>* list = new LinkedList<int>();

	EXPECT_NO_THROW(list->PushFront(1));
}

TEST(LinkedListTests, ListShouldBeAbleToStoreChars)
{
	LinkedList<char>* list = new LinkedList<char>();

	EXPECT_NO_THROW(list->PushFront('a'));
}

TEST(LinkedListTests, ListShouldBeAbleToStoreDoubles)
{
	LinkedList<double>* list = new LinkedList<double>();

	EXPECT_NO_THROW(list->PushFront(0.05));
}

TEST(LinkedListTests, WhenWrongIndexIsCalledNullShouldBeReturnedFromGetData)
{
	LinkedList<std::string>* list = new LinkedList<std::string>();
	list->PushBack("string1");
	list->PushBack("string2");
	list->PushBack("string3");
	list->PushBack("string4");

	EXPECT_EQ("" , list->getData(4));
}

TEST(LinkedListTests, WhenRightIndexIsCalledCorrectDataShouldBeReturnedFromGetData)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushBack(1);
	list->PushBack(2);
	list->PushBack(3);
	list->PushBack(4);

	EXPECT_EQ(2, list->getData(1));
}

TEST(LinkedListTests, WhenMixingPushAndPopSizeShouldBeCorrect)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushBack(1);
	list->PopBack();
	list->PushFront(2);
	list->PushBack(3);
	list->PushBack(4);
	list->PopFront();
	list->PushFront(5);

	EXPECT_EQ(3, list->Size());
}






//TEST(LinkedListtests, CheckSize) {
//	LinkedList<int>* List = new LinkedList<int>();
//	List->PushBack(9);
//	List->PushBack(3);
//	List->PushBack(2);
//	
//	EXPECT_EQ(3, List<int>.size());
//}
//
//TEST(LinkedListTests, TestIfTheStringsAreEqual) {
//	LinkedList<std::string>* List = new LinkedList<std::string>();
//	std::string hej = "HEJ";
//	List->PushFront(hej);
//	
//	EXPECT_EQ(hej, List->PopFront());
//
//}
//
//TEST(LinkedListTests, TestIfTheStringsAreEqual) {
//	std::string hej = "HEJ";
//
//	EXPECT_STREQ("hej", "hej");
//
//}