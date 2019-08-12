#include <algorithm>
using namespace std;

// 4 ms, 8.5 MB. DP
class Solution {
public:
    int integerBreak(int n) {
        int *memo = new int[n + 1];
        memo[0] = 0; memo[1] = 1;
        for (int i = 2; i <= n; ++ i)
            memo[i] = i - 1;

        for (int i = 3; i <= n; ++ i)
            for (int j = i - 2; j > 0; --j)
                memo[i] = max(memo[i], max(j * memo[i - j], j * (i - j)));

        return memo[n];
    }
};