#include <string>
#include <vector>
using namespace std;

// 8 ms, 12.7 MB.
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    string ret;
    int curr_row = 0;
    bool down;
    vector<string> aux(numRows);
    for (auto &c : s) {
      if (curr_row == 0) {
        down = true;
      } else if (curr_row == numRows - 1) {
        down = false;
      }
      aux[curr_row] += c;
      if (down) {
        ++curr_row;
      } else {
        --curr_row;
      }
    }
    for (const auto &s : aux) {
      ret += s;
    }
    return ret;
  }
};