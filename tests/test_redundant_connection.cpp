#include "redundant_connection.h"
#include <gtest/gtest.h>

TEST(RedundantConnectionTests, VeryBasic) {
    {
        std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
        EXPECT_EQ(findRedundantConnection(edges), (std::vector<int>{2, 3}));
    }
    {
        std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
        EXPECT_EQ(findRedundantConnection(edges), (std::vector<int>{1, 4}));
    }
    {
        std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {1, 4}, {3, 4}};
        EXPECT_EQ(findRedundantConnection(edges), (std::vector<int>{3, 4}));
    }
    {
        std::vector<std::vector<int>> edges = {{1, 2}, {1, 2}};
        EXPECT_EQ(findRedundantConnection(edges), (std::vector<int>{1, 2}));
    }
}
