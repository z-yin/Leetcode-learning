// 0 ms, DP
class Solution {
public:
    int climbStairs(int n) {
        int memo[2] = {1, 1};
        
        for (int i = 2; i <= n; ++ i)
            memo[i%2] = memo[0] + memo[1];
        
        return memo[n%2];
    }
};