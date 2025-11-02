#include "LinkedList.h"
#include <gtest/gtest.h>

TEST(LinkedListTests, VeryBasicAppendAndGetHead) {
  LinkedList<int> list;
  list.append(10);
  EXPECT_EQ(list.getHead(), 10);

  list.append(20);
  EXPECT_EQ(list.getHead(), 10);

  list.append(30);
  EXPECT_EQ(list.getHead(), 10);

  list.remove(10);
  EXPECT_EQ(list.getHead(), 20);
}
