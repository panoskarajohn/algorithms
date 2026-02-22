#include "PrefixTree.h"
#include "WordDictionary.h"

#include <gtest/gtest.h>

TEST(PrefixTree, VeryBasic) {
    {
        PrefixTree tree;
        EXPECT_FALSE(tree.startsWith("a"));
        EXPECT_FALSE(tree.startsWith("cat"));
    }

    {
        PrefixTree tree;
        tree.insert("cat");

        EXPECT_TRUE(tree.startsWith("c"));
        EXPECT_TRUE(tree.startsWith("ca"));
        EXPECT_TRUE(tree.startsWith("cat"));
        EXPECT_FALSE(tree.startsWith("cats"));
        EXPECT_FALSE(tree.startsWith("car"));
    }

    {
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

    {
        PrefixTree tree;
        tree.insert("cat");
        tree.insert("cat");

        EXPECT_TRUE(tree.startsWith("c"));
        EXPECT_TRUE(tree.startsWith("ca"));
        EXPECT_TRUE(tree.startsWith("cat"));
    }

    {
        PrefixTree tree;
        tree.insert("cater");

        EXPECT_TRUE(tree.startsWith("cat"));
        EXPECT_TRUE(tree.startsWith("cate"));
        EXPECT_TRUE(tree.startsWith("cater"));
        EXPECT_FALSE(tree.startsWith("cattle"));
    }

    {
        PrefixTree tree;

        EXPECT_FALSE(tree.search("cat"));
        EXPECT_FALSE(tree.search("c"));

        tree.insert("cat");
        tree.insert("car");
        tree.insert("dog");

        EXPECT_TRUE(tree.search("cat"));
        EXPECT_TRUE(tree.search("car"));
        EXPECT_TRUE(tree.search("dog"));

        EXPECT_FALSE(tree.search("ca"));
        EXPECT_FALSE(tree.search("do"));
        EXPECT_FALSE(tree.search("cats"));
        EXPECT_FALSE(tree.search("cow"));
    }
}

TEST(WordDictionary, DISABLED_NeetCodeDesignAddAndSearchWordDataStructure) {
    {
        WordDictionary dictionary;
        dictionary.addWord("bad");
        dictionary.addWord("dad");
        dictionary.addWord("mad");

        EXPECT_FALSE(dictionary.search("pad"));
        EXPECT_TRUE(dictionary.search("bad"));
        EXPECT_TRUE(dictionary.search(".ad"));
        EXPECT_TRUE(dictionary.search("b.."));
    }

    {
        WordDictionary dictionary;
        dictionary.addWord("at");
        dictionary.addWord("and");
        dictionary.addWord("an");
        dictionary.addWord("add");

        EXPECT_TRUE(dictionary.search("an"));
        EXPECT_TRUE(dictionary.search("a."));
        EXPECT_TRUE(dictionary.search("a.d"));
        EXPECT_TRUE(dictionary.search("..d"));
        EXPECT_FALSE(dictionary.search("a"));
        EXPECT_FALSE(dictionary.search("."));
        EXPECT_FALSE(dictionary.search("...d"));
    }

    {
        WordDictionary dictionary;
        dictionary.addWord("a");
        dictionary.addWord("ab");
        dictionary.addWord("abc");
        dictionary.addWord("abcd");

        EXPECT_TRUE(dictionary.search("a"));
        EXPECT_TRUE(dictionary.search("."));
        EXPECT_TRUE(dictionary.search("ab"));
        EXPECT_TRUE(dictionary.search("a."));
        EXPECT_TRUE(dictionary.search(".."));
        EXPECT_TRUE(dictionary.search("abc"));
        EXPECT_TRUE(dictionary.search("..."));
        EXPECT_TRUE(dictionary.search("...."));

        EXPECT_FALSE(dictionary.search("....."));
        EXPECT_FALSE(dictionary.search("b"));
        EXPECT_FALSE(dictionary.search(".a"));
    }

    {
        WordDictionary dictionary;
        dictionary.addWord("cat");
        dictionary.addWord("cap");
        dictionary.addWord("can");
        dictionary.addWord("dog");

        EXPECT_TRUE(dictionary.search("ca."));
        EXPECT_TRUE(dictionary.search("c.t"));
        EXPECT_TRUE(dictionary.search("d.g"));
        EXPECT_FALSE(dictionary.search("c..t"));
        EXPECT_FALSE(dictionary.search(".."));
        EXPECT_FALSE(dictionary.search("...s"));
    }
}
