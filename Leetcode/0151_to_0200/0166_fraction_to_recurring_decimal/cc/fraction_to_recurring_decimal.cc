#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// 0 ms	8.7 MB. Unordered_map.
class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    if (denominator == 0) return "";
    string res;
    if ((numerator < 0) ^ (denominator < 0)) res = "-";
    long long num = abs((long long)numerator);
    long long den = abs((long long)denominator);

    res += to_string(num / den);

    long long rem = num % den * 10;
    if (rem == 0) return res;
    res += '.';

    unordered_map<long long, int> mp;
    while (rem != 0) {
      if (mp.count(rem)) {
        string part1 = res.substr(0, mp[rem]);
        string part2 = res.substr(mp[rem], res.size() - mp[rem]);
        return part1 + '(' + part2 + ')';
      }
      mp[rem] = res.size();
      res += to_string(rem / den);
      rem = rem % den * 10;
    }
    return res;
  }
};