#include "gtest/gtest.h"
#include "../TemplateClasses/Queue.h"

TEST(QueueTests, WhenPushingQueueSizeShouldIncrease) 
{
	Queue<int> *intQueue = new Queue<int>;
	intQueue->Push(1);
	intQueue->Push(2);
	intQueue->Push(3);
  EXPECT_EQ(3, intQueue->Size());
}

TEST(QueueTests, WhenPopingQueueSizeShouldDecrease)
{
	Queue<int> *intQueue = new Queue<int>;
	intQueue->Push(1);
	intQueue->Push(2);
	intQueue->Push(3);
	intQueue->Pop();
	EXPECT_EQ(2, intQueue->Size());
}

TEST(QueueTests, WhenPopingDataShouldBeReturned)
{
	Queue<int> *intQueue = new Queue<int>;
	intQueue->Push(1);
	intQueue->Push(2);
	intQueue->Push(3);
	EXPECT_EQ(1, intQueue->Pop());
}

TEST(QueueTests, WhenMixingPopAndPushQueueSizeShouldStillReturnCorrectSize)
{
	Queue<int> *intQueue = new Queue<int>;
	intQueue->Push(1);
	intQueue->Push(2);
	intQueue->Push(3);
	intQueue->Pop();
	intQueue->Push(4);
	intQueue->Push(5);
	intQueue->Pop();
	intQueue->Pop();
	intQueue->Push(6);
	EXPECT_EQ(3, intQueue->Size());
}

TEST(QueueTests, WhenMixingPopAndPushQueueSizeShouldStillReturnCorrectData)
{
	Queue<int> *intQueue = new Queue<int>;
	intQueue->Push(1);
	intQueue->Push(2);
	intQueue->Push(3);
	intQueue->Pop();
	intQueue->Push(4);
	intQueue->Push(5);
	intQueue->Pop();
	intQueue->Pop();
	intQueue->Push(6);
	EXPECT_EQ(4, intQueue->Pop());
}