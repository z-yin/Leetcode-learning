#include <string>
#include <vector>
using namespace std;

// 4 ms, 8.9 MB
class Solution {
 private:
  vector<string> ret;

  void __restoreIpAddresses(const string &str, int start, int remain,
                            const string &s) {
    if (start == str.size()) {
      ret.emplace_back(s.substr(0, s.size() - 1));
      return;
    }

    if (str[start] == '0') {
      string::size_type charRemain = str.size() - (start + 1);
      if (charRemain >= remain - 1 && charRemain <= (remain - 1) * 3)
        __restoreIpAddresses(str, start + 1, remain - 1, s + "0.");
      return;
    }

    for (int i = 1; i <= 3; ++i) {
      string subs = str.substr(start, i);
      string::size_type charRemain = str.size() - (start + i);
      if (charRemain >= remain - 1 && charRemain <= (remain - 1) * 3 &&
          stoi(subs) <= 255)
        __restoreIpAddresses(str, start + i, remain - 1, s + subs + '.');
    }
  }

 public:
  vector<string> restoreIpAddresses(string s) {
    ret.clear();
    if (s.size() < 4 || s.size() > 12) return ret;

    __restoreIpAddresses(s, 0, 4, "");
    return ret;
  }
};