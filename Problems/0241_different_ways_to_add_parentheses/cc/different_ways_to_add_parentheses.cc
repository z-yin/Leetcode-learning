#include <map>
#include <string>
#include <vector>
using namespace std;

// 0 ms, 9.4 MB. Divide and conquer. Memoization.
class Solution {
 public:
  vector<int> diffWaysToCompute(string input) {
    if (memo_.count(input)) {
      return memo_[input];
    }
    vector<int> ret;
    if (input.empty()) return ret;

    for (int i = 0; i < input.size(); ++i) {
      char c = input[i];
      if (isdigit(c)) continue;

      vector<int> l = diffWaysToCompute(input.substr(0, i));
      vector<int> r =
          diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));
      for (int le : l) {
        for (int re : r) {
          ret.emplace_back(calc(le, re, c));
        }
      }
    }
    if (ret.empty()) ret.emplace_back(stoi(input));
    memo_[input] = ret;
    return ret;
  }

 private:
  map<string, vector<int>> memo_;
  int calc(int lh, int rh, char opt) {
    int res;
    switch (opt) {
      case '+': {
        res = lh + rh;
        break;
      }
      case '-': {
        res = lh - rh;
        break;
      }
      case '*': {
        res = lh * rh;
        break;
      }
    }
    return res;
  }
};