#include <vector>
#include <algorithm>
using namespace std;

// 4 ms, 8.7 MB. DP

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0] == target ? 1 : 0;

        sort(nums.begin(), nums.end());

        vector<size_t> memo (target + 1, 0);
        memo[0] = 1;

        for (int i = 1; i < target + 1; ++ i)
            for (int k = 0; k < nums.size() && nums[k] <= i; ++ k)
                memo[i] += memo[i - nums[k]];

        return memo[target];
    }
};