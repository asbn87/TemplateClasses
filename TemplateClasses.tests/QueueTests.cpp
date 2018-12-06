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