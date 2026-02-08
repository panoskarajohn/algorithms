#include "LinkedList.h"
#include <gtest/gtest.h>
#include <linked_list_problem.h>

TEST(LinkedListTests, VeryBasic) {
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

TEST(MiddleOfLinkedList, VeryBasic) {
    {
        std::shared_ptr<Node<int>> head = nullptr;
        auto mid = middleNode(head);
        EXPECT_EQ(mid, nullptr);
    }

    {
        LinkedList<int> list;
        list.append(42);

        auto mid = middleNode(list.head);
        ASSERT_NE(mid, nullptr);
        EXPECT_EQ(mid->data, 42);
    }

    {
        LinkedList<int> list;
        list.append(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);

        auto mid = middleNode(list.head);
        ASSERT_NE(mid, nullptr);
        EXPECT_EQ(mid->data, 3);
    }

    {
        LinkedList<int> list;
        list.append(10);
        list.append(20);
        list.append(30);
        list.append(40);

        auto mid = middleNode(list.head);
        ASSERT_NE(mid, nullptr);
        EXPECT_EQ(mid->data, 30);
    }

    {
        LinkedList<int> list;
        list.append(5);
        list.append(6);
        list.append(7);
        list.append(8);
        list.append(9);
        list.append(10);

        auto mid = middleNode(list.head);
        ASSERT_NE(mid, nullptr);
        EXPECT_EQ(mid->data, 8);
    }
}

TEST(MaxTwinSum, VeryBasic) {
    {
        std::shared_ptr<Node<int>> head = nullptr;
        EXPECT_EQ(maxTwinSum(head), 0);
    }

    {
        LinkedList<int> list;
        list.append(5);
        list.append(4);
        list.append(2);
        list.append(1);
        EXPECT_EQ(maxTwinSum(list.head), 6);
    }

    {
        LinkedList<int> list;
        list.append(4);
        list.append(2);
        list.append(2);
        list.append(3);
        EXPECT_EQ(maxTwinSum(list.head), 7);
    }

    {
        LinkedList<int> list;
        list.append(1);
        list.append(100000);
        EXPECT_EQ(maxTwinSum(list.head), 100001);
    }
}
