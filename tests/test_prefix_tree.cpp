#include "PrefixTree.h"
#include "WordDictionary.h"
#include "WordFilter.h"
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

    {
        WordDictionary dictionary;

        expectSearch(dictionary, "", false);
        expectSearch(dictionary, ".", false);
        expectSearch(dictionary, "...", false);
    }

    {
        WordDictionary dictionary;
        dictionary.addWord("bad");
        dictionary.addWord("bad");

        expectSearch(dictionary, "bad", true);
        expectSearch(dictionary, "b..", true);
        expectSearch(dictionary, "ba", false);
        expectSearch(dictionary, "b...", false);
    }

    {
        WordDictionary dictionary;
        dictionary.addWord("apple");
        dictionary.addWord("apply");
        dictionary.addWord("apt");
        dictionary.addWord("maple");

        expectSearch(dictionary, "app.e", true);
        expectSearch(dictionary, "appl.", true);
        expectSearch(dictionary, "a..le", true);
        expectSearch(dictionary, ".....", true);
        expectSearch(dictionary, "..p..", true);
        expectSearch(dictionary, "....", false);
        expectSearch(dictionary, "......", false);
    }

    {
        WordDictionary dictionary;
        dictionary.addWord("aa");
        dictionary.addWord("ab");
        dictionary.addWord("ba");
        dictionary.addWord("bb");

        expectSearch(dictionary, "..", true);
        expectSearch(dictionary, ".a", true);
        expectSearch(dictionary, "a.", true);
        expectSearch(dictionary, "c.", false);
        expectSearch(dictionary, ".c", false);
    }
}

TEST(WordFilter, VeryBasic) {
    {
        std::vector<std::string> words = {"apple"};
        WordFilter filter(words);

        const int resultPrefixA = filter.f("a", "e");
        ASSERT_EQ(resultPrefixA, 0);

        const int resultPrefixApp = filter.f("app", "le");
        ASSERT_EQ(resultPrefixApp, 0);

        const int resultEmptyPrefix = filter.f("", "e");
        ASSERT_EQ(resultEmptyPrefix, 0);

        const int resultEmptySuffix = filter.f("app", "");
        ASSERT_EQ(resultEmptySuffix, 0);

        const int resultMissingPrefix = filter.f("b", "e");
        ASSERT_EQ(resultMissingPrefix, -1);
    }

    {
        std::vector<std::string> words = {"apple", "apply", "ape", "apple"};
        WordFilter filter(words);

        const int resultAppLe = filter.f("app", "le");
        ASSERT_EQ(resultAppLe, 3);

        const int resultApE = filter.f("ap", "e");
        ASSERT_EQ(resultApE, 3);

        const int resultApLy = filter.f("ap", "ly");
        ASSERT_EQ(resultApLy, 1);

        const int resultEmptyPrefixLe = filter.f("", "le");
        ASSERT_EQ(resultEmptyPrefixLe, 3);

        const int resultNoSuffixMatch = filter.f("a", "z");
        ASSERT_EQ(resultNoSuffixMatch, -1);
    }

    {
        std::vector<std::string> words = {"cat", "car", "cart", "dog"};
        WordFilter filter(words);

        const int resultCaT = filter.f("ca", "t");
        ASSERT_EQ(resultCaT, 2);

        const int resultCarR = filter.f("car", "r");
        ASSERT_EQ(resultCarR, 1);

        const int resultDG = filter.f("d", "g");
        ASSERT_EQ(resultDG, 3);

        const int resultEmptyPrefixT = filter.f("", "t");
        ASSERT_EQ(resultEmptyPrefixT, 2);

        const int resultPrefixCarEmptySuffix = filter.f("car", "");
        ASSERT_EQ(resultPrefixCarEmptySuffix, 2);

        const int resultMissingPrefixEmptySuffix = filter.f("z", "");
        ASSERT_EQ(resultMissingPrefixEmptySuffix, -1);
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
            {'i', 'h', 't', 'r'},
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
            {'a', 'b'},
            {'c', 'd'},
        };
        std::vector<std::string> words = {"acdb", "abdc", "abcd", "bdca"};
        expectFindWords(board, words, {"acdb", "abdc", "bdca"});
    }

    {
        std::vector<std::vector<char>> board = {
            {'a', 'a'},
            {'a', 'a'},
        };
        std::vector<std::string> words = {"a", "aa", "aaa", "aaaa", "aaaaa"};
        expectFindWords(board, words, {"a", "aa", "aaa", "aaaa"});
    }

    {
        std::vector<std::vector<char>> board = {
            {'s', 'e', 'e'},
            {'s', 'f', 'c'},
            {'a', 'd', 'e'},
        };
        std::vector<std::string> words = {"see", "se", "seed", "sef", "sfce"};
        expectFindWords(board, words, {"see", "se", "sef", "sfce"});
    }

    {
        std::vector<std::vector<char>> board = {
            {'o', 'a', 'b', 'n'},
            {'o', 't', 'a', 'e'},
            {'a', 'h', 'k', 'r'},
            {'a', 'f', 'l', 'v'},
        };
        std::vector<std::string> words = {"oa", "oaa", "oath", "oat", "eat", "rain"};
        expectFindWords(board, words, {"oa", "oaa", "eat", "oath", "oat"});
    }
}
