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

TEST(LinkedListCycleDetection, VeryBasic) {
    {
        std::shared_ptr<Node<int>> head = nullptr;
        EXPECT_FALSE(hasCycle(head));
    }

    {
        auto head = std::make_shared<Node<int>>(1);
        EXPECT_FALSE(hasCycle(head));
    }

    {
        auto head = std::make_shared<Node<int>>(1);
        head->next = head;
        EXPECT_TRUE(hasCycle(head));
    }

    {
        auto n1 = std::make_shared<Node<int>>(1);
        auto n2 = std::make_shared<Node<int>>(2);
        auto n3 = std::make_shared<Node<int>>(3);
        auto n4 = std::make_shared<Node<int>>(4);

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;

        EXPECT_FALSE(hasCycle(n1));
    }

    {
        auto n1 = std::make_shared<Node<int>>(10);
        auto n2 = std::make_shared<Node<int>>(20);
        auto n3 = std::make_shared<Node<int>>(30);
        auto n4 = std::make_shared<Node<int>>(40);

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = n1;

        EXPECT_TRUE(hasCycle(n1));
    }

    {
        auto n1 = std::make_shared<Node<int>>(5);
        auto n2 = std::make_shared<Node<int>>(6);
        auto n3 = std::make_shared<Node<int>>(7);
        auto n4 = std::make_shared<Node<int>>(8);
        auto n5 = std::make_shared<Node<int>>(9);

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = n5;
        n5->next = n3;

        EXPECT_TRUE(hasCycle(n1));
    }
}

TEST(LinkedListCycle2, VeryBasic) {
    {
        std::shared_ptr<Node<int>> head = nullptr;
        EXPECT_EQ(detectCycle(head), nullptr);
    }

    {
        auto head = std::make_shared<Node<int>>(1);
        EXPECT_EQ(detectCycle(head), nullptr);
    }

    {
        auto head = std::make_shared<Node<int>>(1);
        head->next = head;
        EXPECT_EQ(detectCycle(head), head);
    }

    {
        auto n1 = std::make_shared<Node<int>>(1);
        auto n2 = std::make_shared<Node<int>>(2);
        auto n3 = std::make_shared<Node<int>>(3);
        auto n4 = std::make_shared<Node<int>>(4);

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;

        EXPECT_EQ(detectCycle(n1), nullptr);
    }

    {
        auto n1 = std::make_shared<Node<int>>(10);
        auto n2 = std::make_shared<Node<int>>(20);
        auto n3 = std::make_shared<Node<int>>(30);
        auto n4 = std::make_shared<Node<int>>(40);

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = n1;

        EXPECT_EQ(detectCycle(n1), n1);
    }

    {
        auto n1 = std::make_shared<Node<int>>(5);
        auto n2 = std::make_shared<Node<int>>(6);
        auto n3 = std::make_shared<Node<int>>(7);
        auto n4 = std::make_shared<Node<int>>(8);
        auto n5 = std::make_shared<Node<int>>(9);

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = n5;
        n5->next = n3;

        EXPECT_EQ(detectCycle(n1), n3);
    }

    {
        auto n1 = std::make_shared<Node<int>>(1);
        auto n2 = std::make_shared<Node<int>>(2);
        auto n3 = std::make_shared<Node<int>>(3);
        auto n4 = std::make_shared<Node<int>>(4);
        auto n5 = std::make_shared<Node<int>>(5);

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = n5;
        n5->next = n2;

        EXPECT_EQ(detectCycle(n1), n2);
    }
}
