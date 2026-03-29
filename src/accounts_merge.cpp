#include "accounts_merge.h"
#include <algorithm>
#include <map>

class UnionFindStr {
  public:
    std::unordered_map<std::string, std::string> parents;
    std::string find(const std::string &target) {
        if (parents.find(target) == parents.end()) {
            parents[target] = target;
        }
        if (parents[target] != target) {
            parents[target] = find(parents[target]);
        }
        return parents[target];
    }

    void unite(const std::string &a, const std::string &b) { parents[find(a)] = find(b); }
};

std::vector<std::vector<std::string>>
accountsMerge(std::vector<std::vector<std::string>> &accounts) {
    UnionFindStr uf;
    std::unordered_map<std::string, std::string> emailName;

    for (const auto &account : accounts) {
        std::string name = account[0];
        for (int i = 1; i < static_cast<int>(account.size()); i++) {
            emailName[account[i]] = name; // we set the email as a key to ensure uniqueness
            uf.unite(account[1], account[i]);
        }
    }

    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (auto &[email, name] : emailName) {
        groups[uf.find(email)].push_back(email);
    }

    std::vector<std::vector<std::string>> result;
    for (auto &[root, emails] : groups) {
        std::vector<std::string> acc = {emailName[root]};
        acc.insert(acc.end(), emails.begin(), emails.end());
        result.push_back(acc);
    }

    return result;
}
