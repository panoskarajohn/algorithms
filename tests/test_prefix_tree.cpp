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

TEST(WordDictionary, VeryBasic) {
    const auto expectSearch = [](const WordDictionary &dictionary, const std::string &word,
                                 bool expected) {
        ASSERT_EQ(dictionary.search(word), expected);
        ASSERT_EQ(dictionary.searchIterative(word), expected);
    };

    {
        WordDictionary dictionary;
        dictionary.addWord("bad");
        dictionary.addWord("dad");
        dictionary.addWord("mad");

        expectSearch(dictionary, "pad", false);
        expectSearch(dictionary, "bad", true);
        expectSearch(dictionary, ".ad", true);
        expectSearch(dictionary, "b..", true);
    }

    {
        WordDictionary dictionary;
        dictionary.addWord("at");
        dictionary.addWord("and");
        dictionary.addWord("an");
        dictionary.addWord("add");

        expectSearch(dictionary, "an", true);
        expectSearch(dictionary, "a.", true);
        expectSearch(dictionary, "a.d", true);
        expectSearch(dictionary, "..d", true);
        expectSearch(dictionary, "a", false);
        expectSearch(dictionary, ".", false);
        expectSearch(dictionary, "...d", false);
    }

    {
        WordDictionary dictionary;
        dictionary.addWord("a");
        dictionary.addWord("ab");
        dictionary.addWord("abc");
        dictionary.addWord("abcd");

        expectSearch(dictionary, "a", true);
        expectSearch(dictionary, ".", true);
        expectSearch(dictionary, "ab", true);
        expectSearch(dictionary, "a.", true);
        expectSearch(dictionary, "..", true);
        expectSearch(dictionary, "abc", true);
        expectSearch(dictionary, "...", true);
        expectSearch(dictionary, "....", true);

        expectSearch(dictionary, ".....", false);
        expectSearch(dictionary, "b", false);
        expectSearch(dictionary, ".a", false);
    }

    {
        WordDictionary dictionary;
        dictionary.addWord("cat");
        dictionary.addWord("cap");
        dictionary.addWord("can");
        dictionary.addWord("dog");

        expectSearch(dictionary, "ca.", true);
        expectSearch(dictionary, "c.t", true);
        expectSearch(dictionary, "d.g", true);
        expectSearch(dictionary, "c..t", false);
        expectSearch(dictionary, "..", false);
        expectSearch(dictionary, "...s", false);
    }
}
