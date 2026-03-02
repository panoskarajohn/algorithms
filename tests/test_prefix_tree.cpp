#include "PrefixTree.h"
#include "WordDictionary.h"
#include "prefix_tree_problems.h"

#include <gtest/gtest.h>

#include <algorithm>

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

TEST(WordSearch2, VeryBasic) {
    const auto expectFindWords = [](std::vector<std::vector<char>> board,
                                    std::vector<std::string> words,
                                    std::vector<std::string> expected) {
        auto result = findWords(board, words);
        std::sort(result.begin(), result.end());
        std::sort(expected.begin(), expected.end());
        ASSERT_EQ(result, expected);
    };

    {
        std::vector<std::vector<char>> board = {
            {'o', 'a', 'a', 'n'},
            {'e', 't', 'a', 'e'},
            {'i', 'h', 'k', 'r'},
            {'i', 'f', 'l', 'v'},
        };
        std::vector<std::string> words = {"oath", "pea", "eat", "rain"};
        expectFindWords(board, words, {"eat", "oath"});
    }

    {
        std::vector<std::vector<char>> board = {{'a', 'b'}, {'c', 'd'}};
        std::vector<std::string> words = {"abcb"};
        expectFindWords(board, words, {});
    }

    {
        std::vector<std::vector<char>> board = {{'a', 'a'}};
        std::vector<std::string> words = {"a", "aa", "aaa"};
        expectFindWords(board, words, {"a", "aa"});
    }

    {
        std::vector<std::vector<char>> board = {{'a'}};
        std::vector<std::string> words = {"a", "b"};
        expectFindWords(board, words, {"a"});
    }

    {
        std::vector<std::vector<char>> board = {
            {'a', 'b', 'c'},
            {'a', 'e', 'd'},
            {'a', 'f', 'g'},
        };
        std::vector<std::string> words = {"abcdefg", "gfedcbaaa", "eaabcdgfa",
                                          "befa",    "dgc",       "ade"};
        expectFindWords(board, words, {"abcdefg", "befa", "eaabcdgfa", "gfedcbaaa"});
    }
}
