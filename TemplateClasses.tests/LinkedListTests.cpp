#include "gtest/gtest.h"
#include "../TemplateClasses/LinkedList.h"
#include <iostream>
#include <cstdlib>
using namespace std;


TEST(LinkedListtrests, AddNode) {

	LinkedList list;
	list.AddNode(3);
	list.AddNode(5);
	list.AddNode(7);
	list.AddNode(2);
	cout << n << endl;


  EXPECT_EQ(1, 1);
  EXPECT_TRUE(3572);
}