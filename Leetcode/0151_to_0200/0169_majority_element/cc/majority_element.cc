#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 12 ms, 11.8 MB. Bucket. The majority element will finally kick out all the
// other elements from the bucket.
class Solution1 {
 public:
  Solution1() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }

  int majorityElement(vector<int>& nums) {
    stack<int> s;
    for (auto& num : nums) {
      if (s.empty() || s.top() == num) {
        s.emplace(num);
      } else if (s.top() != num) {
        s.pop();
      }
    }
    return s.top();
  }
};

// 8 ms, 11 MB. Bit manipulation.
class Solution2 {
 public:
  Solution2() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }

  int majorityElement(vector<int>& nums) {
    vector<int> bits(32, 0);
    for (auto& num : nums) {
      for (int i = 0; i < 32; ++i) {
        if (num >> i & 1) {
          ++bits[i];
        }
      }
    }
    int res = 0;
    for (int i = 0; i < 32; ++i) {
      if (bits[i] > nums.size() / 2) {
        res |= 1 << i;
      }
    }
    return res;
  }
};