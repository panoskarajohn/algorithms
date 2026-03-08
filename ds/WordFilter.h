#include <memory>
#include <string>
#include <vector>

class WordFilter {
  public:
    WordFilter(const std::vector<std::string> &words);
    ~WordFilter();
    int f(std::string prefix, std::string suffix);

  private:
    struct Node;
    std::unique_ptr<Node> root;
    int charToIndex(char c) const;
};
