#include <algorithm>
using namespace std;

// 104 ms, 11.3 MB
class Solution {
public:
    int numSquares(int n) {
        int *memo = new int[n + 1];
        memo[0] = 0;
        for (int i = 1; i < n + 1; ++ i)
            memo[i] = INT_MAX;
        
        for (int i = 1; i < n + 1; ++ i) {
            for (int sqr = 1, mx = sqrt(i); sqr <= mx; ++ sqr) {
                memo[i] = min(memo[i], 1 + memo[i - sqr*sqr]);
            }
        }
        return memo[n];
    }
};

