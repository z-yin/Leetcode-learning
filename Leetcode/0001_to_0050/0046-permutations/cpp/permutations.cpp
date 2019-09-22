#include <vector>
#include <unordered_set>
using namespace std;

// 12 ms, 10.6 MB. Backtracking
class Solution {
private:
    vector<vector<int>> ret;
    unordered_set<int> used;
    void __permute (vector<int>& nums, int index, vector<int> vec) {
        
        if (index == nums.size()) {
            ret.emplace_back(vec);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++ i)
            if ( !used.count(nums[i]) ) {
                used.insert(nums[i]);
                vec.emplace_back( nums[i] );
                __permute(nums, index + 1, vec);
                vec.pop_back();
                used.erase(nums[i]);
            }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        ret.clear();
        if (nums.empty()) return ret;
        
        used.clear();
        
        vector<int> tmp;
        tmp.clear();
        __permute(nums, 0, tmp);
        
        return ret;
    }
};