#include <stack>
#include <string>
using namespace std;

// 8 ms	10.8 MB. Stack.
class Solution1 {
 public:
  int calculate(string s) {
    stack<int> nums;
    char sign = '+';
    int n = 0;

    for (int i = 0; i < s.size(); ++i) {
      if (isdigit(s[i])) n = n * 10 + (s[i] - '0');
      if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
        if (sign == '+')
          nums.emplace(n);
        else if (sign == '-')
          nums.emplace(-n);
        else if (sign == '/')
          nums.top() = nums.top() / n;
        else
          nums.top() = nums.top() * n;
        sign = s[i];
        n = 0;
      }
    }

    int res = 0;
    while (!nums.empty()) {
      res += nums.top();
      nums.pop();
    }

    return res;
  }
};

// 8 ms	9.8 MB. O(1).
class Solution2 {
 public:
  int calculate(string s) {
    int res = 0;
    int top = 0;
    char sign = '+';
    int n = 0;
    
    for (int i = 0; i < s.size(); ++i) {
      if (isdigit(s[i])) n = n * 10 + (s[i] - '0');
      if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
        if (sign == '+') {
          res += top;
          top = n;
        } else if (sign == '-') {
          res += top;
          top = -n;
        } else if (sign == '/') {
          top = top / n;
        } else {
          top = top * n;
        }
        sign = s[i];
        n = 0;
      }
    }
    
    res += top;
    return res;
  }
};