#include "LinkedList.h"
#include "linked_list_problem.h"
#include <gtest/gtest.h>

TEST(MiddleOfLinkedList, AllCases) {
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
