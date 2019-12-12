#include <algorithm>
#include <vector>
using namespace std;

// 4 ms	9.3 MB. nlog(n).
class Solution1 {
 public:
  int maxProduct(vector<int>& nums) { return bfs(nums, 0, nums.size() - 1); }

  int bfs(vector<int>& nums, int l, int r) {
    if (l >= r) return nums[l];
    int m = l + (r - l) / 2;
    int lp = bfs(nums, l, m - 1);
    int rp = bfs(nums, m + 1, r);
    int cp = crossProd(nums, l, m, r);
    return max(lp, max(rp, cp));
  }

  int crossProd(vector<int>& nums, int l, int m, int r) {
    // left half
    int prod_max_l = nums[m], prod_min_l = nums[m];
    int prod = nums[m];
    for (int i = m - 1; i >= l; --i) {
      prod *= nums[i];
      if (prod < prod_min_l) prod_min_l = prod;
      if (prod > prod_max_l) prod_max_l = prod;
    }
    // right half
    int prod_max_r = 1, prod_min_r = 1;
    prod = 1;
    for (int i = m + 1; i <= r; ++i) {
      prod *= nums[i];
      if (prod < prod_min_r) prod_min_r = prod;
      if (prod > prod_max_r) prod_max_r = prod;
    }
    return max(prod_min_l * prod_min_r, prod_max_l * prod_max_r);
  }
};

// 4 ms	9.3 MB. O(n).
class Solution2 {
 public:
  int maxProduct(vector<int>& nums) {
    int maxp = nums[0];
    int prod = 1;
    for (int i = 0; i < nums.size(); ++i) {
      prod *= nums[i];
      maxp = max(prod, maxp);
      if (prod == 0) prod = 1;
    }
    prod = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      prod *= nums[i];
      maxp = max(prod, maxp);
      if (prod == 0) prod = 1;
    }
    return maxp;
  }
};