#include "PrefixTree.h"

#include <gtest/gtest.h>

TEST(PrefixTree, StartsWithIsFalseOnEmptyTree) {
    PrefixTree tree;
    EXPECT_FALSE(tree.startsWith("a"));
    EXPECT_FALSE(tree.startsWith("cat"));
}

TEST(PrefixTree, InsertSingleWordSupportsAllPrefixes) {
    PrefixTree tree;
    tree.insert("cat");

    EXPECT_TRUE(tree.startsWith("c"));
    EXPECT_TRUE(tree.startsWith("ca"));
    EXPECT_TRUE(tree.startsWith("cat"));
    EXPECT_FALSE(tree.startsWith("cats"));
    EXPECT_FALSE(tree.startsWith("car"));
}

TEST(PrefixTree, InsertMultipleWordsSupportsBranches) {
    PrefixTree tree;
    tree.insert("cat");
    tree.insert("car");
    tree.insert("dog");

    EXPECT_TRUE(tree.startsWith("ca"));
    EXPECT_TRUE(tree.startsWith("cat"));
    EXPECT_TRUE(tree.startsWith("car"));
    EXPECT_TRUE(tree.startsWith("d"));
    EXPECT_TRUE(tree.startsWith("do"));
    EXPECT_TRUE(tree.startsWith("dog"));

    EXPECT_FALSE(tree.startsWith("cow"));
    EXPECT_FALSE(tree.startsWith("dot"));
}

TEST(PrefixTree, HandlesDuplicateInsertions) {
    PrefixTree tree;
    tree.insert("cat");
    tree.insert("cat");

    EXPECT_TRUE(tree.startsWith("c"));
    EXPECT_TRUE(tree.startsWith("ca"));
    EXPECT_TRUE(tree.startsWith("cat"));
}

TEST(PrefixTree, PrefixOfInsertedWordIsRecognized) {
    PrefixTree tree;
    tree.insert("cater");

    EXPECT_TRUE(tree.startsWith("cat"));
    EXPECT_TRUE(tree.startsWith("cate"));
    EXPECT_TRUE(tree.startsWith("cater"));
    EXPECT_FALSE(tree.startsWith("cattle"));
}
