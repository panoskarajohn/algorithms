#include "connected_components.h"
#include <gtest/gtest.h>

TEST(ConnectedComponents, VeryBasic) {
    {
        // Two components
        EXPECT_EQ(countComponents(5, {{0, 1}, {1, 2}, {3, 4}}), 2);
    }
    {
        // One component
        EXPECT_EQ(countComponents(5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}}), 1);
    }
    {
        // No edges
        EXPECT_EQ(countComponents(4, {}), 4);
    }
    {
        // Single node
        EXPECT_EQ(countComponents(1, {}), 1);
    }
    {
        // All connected
        EXPECT_EQ(countComponents(3, {{0, 1}, {0, 2}, {1, 2}}), 1);
    }
    {
        // Duplicate edges
        EXPECT_EQ(countComponents(4, {{0, 1}, {0, 1}, {2, 3}}), 2);
    }
}
