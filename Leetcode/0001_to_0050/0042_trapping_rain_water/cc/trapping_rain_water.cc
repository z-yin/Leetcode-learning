#include <algorithm>
#include <vector>
using namespace std;

// 4 ms, 9 MB. Two pointers. Important to first divide into two halves.
class Solution {
 public:
  int trap(vector<int>& height) {
    int mid = max_element(height.begin(), height.end()) - height.begin();
    int minus = 0, prev = 0, sum = 0;
    // left half
    for (int i = 1; i <= mid; ++i) {
      if (height[i] == 0) {
        continue;
      }
      if (height[i] >= height[prev]) {
        sum += (i - prev - 1) * height[prev] - minus;
        minus = 0;
        prev = i;
      } else {
        minus += height[i];
      }
    }
    // right half
    prev = height.size() - 1;
    for (int i = height.size() - 2; i >= mid; --i) {
      if (height[i] == 0) {
        continue;
      }
      if (height[i] >= height[prev]) {
        sum += (prev - i - 1) * height[prev] - minus;
        minus = 0;
        prev = i;
      } else {
        minus += height[i];
      }
    }
    return sum;
  }
};