#include <string>
using namespace std;

// 4 ms, 9.1 MB. Two pointers.
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int len_hay = haystack.size();
    int len_nee = needle.size();
    if (len_nee == 0) {
      return 0;
    }

    int i = 0;
    int end = len_hay - len_nee;
    while (i <= end) {
      if (haystack[i] == needle[0]) {
        int j = i + 1;
        while (j - i < len_nee && haystack[j] == needle[j - i]) {
          ++j;
        }
        if (j - i == len_nee) {
          return i;
        }
      }
      ++i;
    }
    return -1;
  }
};