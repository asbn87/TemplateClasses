#include "gtest/gtest.h"
#include "../TemplateClasses/Queue.h"

TEST(QueueTests, PushShouldAddToQueue)
{
	Queue<int>* intQueue = new Queue<int>();
	intQueue->Push(1);

	EXPECT_EQ(1, intQueue->Size());
}

TEST(QueueTests, SizeShouldReturnCorrectLength) 
{
	Queue<int>* intQueue = new Queue<int>();
	intQueue->Push(1);
	intQueue->Push(2);
	intQueue->Pop();
	intQueue->Push(3);

  EXPECT_EQ(2, intQueue->Size());
}

TEST(QueueTests, PopShouldReturnFirstElement)
{
	Queue<int>* intQueue = new Queue<int>();
	intQueue->Push(1);
	intQueue->Push(2);
	intQueue->Push(3);

	EXPECT_EQ(1, intQueue->Pop());
}

TEST(QueueTests, WhenMixingPopAndPushPopShouldStillReturnCorrectData)
{
	Queue<int>* intQueue = new Queue<int>();
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

TEST(QueueTests, QueueShouldBeAbleToStoreAndReturnChars)
{
	Queue<char>* queue = new Queue<char>();
	queue->Push('a');
	queue->Push('b');

	EXPECT_EQ('a', queue->Pop());
}

TEST(QueueTests, QueueShouldBeAbleToStoreAndReturnInts)
{
	Queue<int>* queue = new Queue<int>();
	queue->Push(1);
	queue->Push(2);

	EXPECT_EQ(1, queue->Pop());
}

TEST(QueueTests, QueueShouldBeAbleToStoreStrings)
{
	Queue<std::string>* queue = new Queue<std::string>();
	queue->Push("This is string1");
	queue->Push("This is string2");

	EXPECT_EQ("This is string1", queue->Pop());
}

TEST(QueueTests, PopShouldReturnNoDataWhenQueueIsEmpty)
{
	Queue<int>* queue = new Queue<int>();
	
	EXPECT_EQ(NULL, queue->Pop());
}