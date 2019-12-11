#include <stack>
#include <string>
#include <vector>
using namespace std;

// 16 ms	11.6 MB. Stack.
class Solution {
 public:
  int evalRPN(vector<string>& t) {
    stack<int> s;
    for (int i = 0; i < t.size(); ++i) {
      if (t[i] == "+" || t[i] == "-" || t[i] == "*" || t[i] == "/") {
        int r = s.top();
        s.pop();
        int l = s.top();
        s.pop();
        s.emplace(op(l, r, t[i]));
      } else {
        s.emplace(stoi(t[i]));
      }
    }
    return s.top();
  }

  int op(int l, int r, string& o) {
    if (o == "+") return l + r;
    if (o == "-") return l - r;
    if (o == "*") return l * r;
    return l / r;
  }
};