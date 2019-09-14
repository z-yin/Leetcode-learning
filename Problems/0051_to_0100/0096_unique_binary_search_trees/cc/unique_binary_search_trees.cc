#include <vector>
using namespace std;

// 4 ms, 8.3 MB
class Solution {
 public:
  int numTrees(int n) {
    memo_ = vector<int>(n + 1, 0);
    memo_[0] = 1;
    memo_[1] = 1;
    return GetNumTrees(n);
  }

 private:
  vector<int> memo_;

  int GetNumTrees(const int& n) {
    if (memo_[n] != 0) {
      return memo_[n];
    }
    for (int i = 1; i <= n; ++i) {
      memo_[n] += GetNumTrees(i - 1) * GetNumTrees(n - i);
    }
    return memo_[n];
  }
};