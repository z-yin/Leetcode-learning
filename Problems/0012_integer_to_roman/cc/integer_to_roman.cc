#include <string>
using namespace std;

// 8 ms, 8.2 MB
class Solution {
 public:
  string intToRoman(int num) {
    char* mapping[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int base[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    int base_index = 12;
    string ret;
    while (num != 0) {
      int divide = num / base[base_index];
      num %= base[base_index];
      while (divide) {
        ret += mapping[base_index];
        --divide;
      }
      --base_index;
    }
    return ret;
  }
};