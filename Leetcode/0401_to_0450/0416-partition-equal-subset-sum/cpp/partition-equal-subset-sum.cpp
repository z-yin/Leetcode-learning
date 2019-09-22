#include <vector>
#include <algorithm>
using namespace std;

// 172 ms, 8.3 MB. DP.
class Solution1 {
public:
    bool canPartition(vector<int>& nums) {
        
        if (nums.size() < 2) return false;
        
        int sum = 0;
        for (int i = 0; i < nums.size(); ++ i)
            sum += nums[i];
        
        if ( sum % 2 != 0 ) return false;
        
        int C = sum / 2;
        
        vector<bool> memo ( C + 1, false);
        memo[nums[0]] = true;
        
        for (int j = 1; j < nums.size(); ++ j)
            for (int k = C; k >= nums[j]; -- k)
                memo[k] = memo[k] || memo[k - nums[j]];
                
        return memo[C];
    }
};


// 4 ms, 8.3 MB. Backtraking. From large value to small value to avoid two many small values, making it 
// waste a lot of time adding up to sum / 2.
class Solution2 {
private:
    bool ret;
    void __canPartition (const vector<int>& nums, int index, int sum) {
        
        if (sum == 0) {
            ret = true;
            return;
        }
        
        for (int i = index; i >= 0; -- i) {
            if (nums[i] > sum) continue;
            __canPartition(nums, i - 1, sum - nums[i]);
            if (ret) return;
        }
    }
public:
    bool canPartition(vector<int>& nums) {
        
        if (nums.size() < 2) return false;
        
        int sum = 0;
        for (int i = 0; i < nums.size(); ++ i)
            sum += nums[i];
        
        if ( sum % 2 != 0 ) return false;
        
        int C = sum / 2;
        
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] > C) return false;
            if (nums[i] == C) return true;
        }
            
        sort(nums.begin(), nums.end());
        __canPartition(nums, nums.size() - 1, C);
        
        return ret;
    }
};