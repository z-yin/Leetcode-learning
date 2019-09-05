#include <string>
using namespace std;

// Leetcode has bug with cpp version.
class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1.empty() || num2.empty()) {
      return "";
    }

    string ret;
    if (num1.size() <= num2.size()) {
      ret = help(num2, num1);
    } else {
      ret = help(num1, num2);
    }
    return ret;
  }

 private:
  string help(string &num1, string &num2) {
    string ret;
    for (char c : num2) {
      const string ans = mult2(num1, c);
      add2(ans, ret);
    }
    return ret;
  }

  const string mult2(const string &s, char c) {
    string ret;
    if (c == '0') {
      return "0";
    }
    int cc = c - '0';
    int carry = 0;
    for (int i = (int)s.size() - 1; i >= 0; --i) {
      int ans = (s[i] - '0') * cc + carry;
      ret += ans % 10 + '0';
      carry = ans / 10;
    }
    if (carry != 0) {
      ret += carry + '0';
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  // if s1 : "123", s2 : "456", then adding would be like
  //    123
  // + 456
  // retult is stored in s2
  void add2(const string &s1, string &s2) {
    s2 += '0';
    auto it1 = s1.end();
    auto it2 = s2.end();
    int carry = 0;
    while (it1 != s1.begin() && it2 != s2.begin()) {
      --it1;
      --it2;
      int ans = (*it1 - '0') + (*it2 - '0') + carry;
      *it2 = ans % 10 + '0';
      carry = ans / 10;
    }
    while (it1 != s1.begin()) {
      --it1;
      int ans = (*it1 - '0') + carry;
      s2.insert(0, 1, (char)(ans % 10 + '0'));
      carry = ans / 10;
    }
    while (it2 != s2.begin()) {
      --it2;
      int ans = (*it2 - '0') + carry;
      *it2 = ans % 10 + '0';
      carry = ans / 10;
    }
    if (carry != 0) {
      s2.insert(0, 1, (char)(carry + '0'));
    }
  }
};