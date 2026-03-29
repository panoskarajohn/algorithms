#pragma once

#include <string>
#include <vector>

// Given a list of accounts where each account is a list of strings:
// - accounts[i][0] is the name of the account holder
// - accounts[i][1..] are the email addresses belonging to that account
//
// Two accounts belong to the same person if they share at least one email.
// Merge all such accounts and return them in the following format:
// - The first element is the name
// - The rest are emails in sorted order
// The accounts themselves may be returned in any order.
std::vector<std::vector<std::string>>
accountsMerge(std::vector<std::vector<std::string>> &accounts);
