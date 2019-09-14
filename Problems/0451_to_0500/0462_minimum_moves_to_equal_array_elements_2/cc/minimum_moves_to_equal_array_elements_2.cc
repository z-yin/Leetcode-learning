#include <iostream>
#include <vector>
using namespace std;

// 12 ms. 9.8 MB. \sum_{i=x+1}^{N-1}a_i + \sum_{i=0}^{x-1}a_i + (2*x-n+2)*a_x
// O(N)
class Solution1 {
 public:
  Solution1() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }

  int minMoves2(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int N = nums.size();
    vector<int> sum(N, 0);
    sum[0] = nums[0];
    for (int i = 1; i < N; ++i) {
      sum[i] = sum[i - 1] + nums[i];
    }
    long long res = INT_MAX;
    for (int i = 0; i < N; ++i) {
      long long left = sum[i];
      long long right = sum[N - 1] - sum[i];
      long long mid = (2 * i - N + 2) * (long long)nums[i];
      res = min(res, right - left + mid);
    }
    return res;
  }
};

// 4 ms, 9.5 MB. Median element is the final equal value.
class Solution2 {
 public:
  Solution2() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }

  int minMoves2(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int mid = nums[nums.size() / 2];
    int res = 0;
    for (auto &num : nums) {
      res += abs(num - mid);
    }
    return res;
  }
};
