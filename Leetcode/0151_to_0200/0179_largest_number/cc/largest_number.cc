#include <string>
#include <vector>
using namespace std;

// 8 ms	9.1 MB. Customized sort.
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> vs;
    for (int& i : nums) vs.emplace_back(to_string(i));
    sort(vs.begin(), vs.end(),
         [](const string& a, const string& b) { return a + b > b + a; });
    string res;
    for (auto& i : vs) res += i;
    if (res[0] == '0') return "0";
    return res;
  }
};