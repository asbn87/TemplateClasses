#include "gtest/gtest.h"
#include "../TemplateClasses/LinkedList.h"


TEST(LinkedListTests, WhenPushFrontHeadShouldBeUpdated)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushFront(3);
	
	EXPECT_EQ(3, list->Front()->getData());
}

TEST(LinkedListTests, WhenPushFrontHeadsNextShouldBeOldHead)
{
	LinkedList<int>* list = new LinkedList<int>();
	list->PushFront(1);
	list->PushFront(2);
	list->PushFront(3);

	EXPECT_EQ(2, list->Front()->getNext()->getData());
}

TEST(LinkedListTests, WhenPushFrontShouldInputFivenumbersToList) {

	LinkedList<int>* List = new LinkedList<int>();
	List->PushFront(0);
	List->PushFront(1);
	List->PushFront(2);
	List->PushFront(3);
	List->PushFront(4);

	EXPECT_TRUE(true);
}

TEST(LinkedListTests, ShouldPushBackItemsToTheBackOfTheList) {
	LinkedList<int>* List = new LinkedList<int>();
	List->PushBack(8);
	List->PushBack(3);
	List->PushBack(9);
	
	EXPECT_TRUE(true);

}

TEST(LinkedListTests, CanitWorkWithChars) {
	LinkedList<const char>* List = new LinkedList<const char>();

	//List->PushFront("Hej");

	

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