#include "accounts_merge.h"
#include <algorithm>
#include <gtest/gtest.h>

// Normalizes result for comparison: sorts emails within each account,
// then sorts accounts lexicographically.
static std::vector<std::vector<std::string>>
normalize(std::vector<std::vector<std::string>> accounts) {
    for (auto &account : accounts) {
        std::sort(account.begin() + 1, account.end());
    }
    std::sort(accounts.begin(), accounts.end());
    return accounts;
}

TEST(AccountsMerge, VeryBasic) {
    using Accounts = std::vector<std::vector<std::string>>;

    // No overlap
    {
        Accounts input = {{"Alice", "alice@example.com"}, {"Bob", "bob@example.com"}};
        Accounts expected = {{"Alice", "alice@example.com"}, {"Bob", "bob@example.com"}};
        auto result = normalize(accountsMerge(input));
        ASSERT_EQ(result, normalize(expected));
    }

    // Two accounts merged by shared email
    {
        Accounts input = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                          {"John", "johnsmith@mail.com", "john00@mail.com"},
                          {"Mary", "mary@mail.com"},
                          {"John", "johnnybravo@mail.com"}};
        Accounts expected = {
            {"John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"},
            {"Mary", "mary@mail.com"},
            {"John", "johnnybravo@mail.com"}};
        auto result = normalize(accountsMerge(input));
        ASSERT_EQ(result, normalize(expected));
    }

    // Transitive merge: A-B share email, B-C share email -> all merge
    {
        Accounts input = {{"Alice", "a@mail.com", "b@mail.com"},
                          {"Alice", "b@mail.com", "c@mail.com"},
                          {"Alice", "c@mail.com", "d@mail.com"}};
        Accounts expected = {{"Alice", "a@mail.com", "b@mail.com", "c@mail.com", "d@mail.com"}};
        auto result = normalize(accountsMerge(input));
        ASSERT_EQ(result, normalize(expected));
    }

    // Same name but no shared emails -> remain separate
    {
        Accounts input = {{"David", "david1@mail.com", "david2@mail.com"},
                          {"David", "david3@mail.com", "david4@mail.com"}};
        Accounts expected = {{"David", "david1@mail.com", "david2@mail.com"},
                             {"David", "david3@mail.com", "david4@mail.com"}};
        auto result = normalize(accountsMerge(input));
        ASSERT_EQ(result, normalize(expected));
    }

    // Single account
    {
        Accounts input = {{"Alice", "only@mail.com"}};
        Accounts expected = {{"Alice", "only@mail.com"}};
        auto result = normalize(accountsMerge(input));
        ASSERT_EQ(result, normalize(expected));
    }

    // Empty input
    {
        Accounts input = {};
        ASSERT_EQ(accountsMerge(input), Accounts{});
    }
}
