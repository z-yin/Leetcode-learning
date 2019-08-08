#include <vector>
#include <algorithm>
using namespace std;

// 16 ms, 9.9 MB
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = INT_MIN;
        
        for (int i = 0, j = height.size() - 1; i < j; height[i] > height[j] ? --j : ++i) {
            ret = max( (j - i) * min(height[i], height[j]), ret );
        }
        return ret;
    }
};