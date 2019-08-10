#include <vector>
#include <algorithm>
using namespace std;


// 8 ms, 9.6 MB. Backtracking
class Solution {
private:
    vector<vector<int>> ret;

    void __combinationSum(const vector<int>& candi, const int& target, int start, vector<int>& c, int sum) {
        if (sum == target) {
            ret.emplace_back(c);
            return;
        }

        if (sum < target) {
            for (int i = start; i < candi.size() && candi[i] + sum <= target; ++ i) {
                c.emplace_back(candi[i]);
                __combinationSum(candi, target, i, c, sum + candi[i]);
                c.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        ret.clear();
        if (candidates.empty()) return ret;

        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        tmp.clear();
        __combinationSum(candidates, target, 0, tmp, 0);

        return ret;
    }
};