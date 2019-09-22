#include <vector>
#include <algorithm>
using namespace std;


// 8 ms, 9.2 MB. Backtracking
class Solution {
private:
    vector<vector<int>> ret;
    
    void __combinationSum2 (vector<int>& candi, int target, int start, vector<int>& c, int sum) {
        
        if (sum == target) {
            ret.emplace_back(c);
            return;
        }
        
        if (sum < target) {
            for (int i = start; i < candi.size() && sum + candi[i] <= target; ++ i) {
                if (i > start && candi[i] == candi[i - 1]) continue;
                c.emplace_back(candi[i]);
                __combinationSum2(candi, target, i + 1, c, sum + candi[i]);
                c.pop_back();
            }
        }
    } 
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        ret.clear();
        if (candidates.empty()) return ret;
        
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        tmp.clear();
        __combinationSum2(candidates, target, 0, tmp, 0);
         
        return ret;
    }
};