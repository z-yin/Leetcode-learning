#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 24 ms, 10.5 MB. Backtracking
class Solution {
private:
    vector<vector<int>> ret;
    unordered_map<int, int> numOfUnused;

    void __permuteUnique (const int& n, const unordered_set<int>& nums, int index, vector<int>& vec) {

        if (index == n) {
            ret.emplace_back(vec);
            return;
        }

        for (auto i = nums.begin(); i != nums.end(); ++ i) {
            if (numOfUnused[*i] > 0) {
                vec.emplace_back(*i);
                --numOfUnused[*i];
                __permuteUnique(n, nums, index + 1, vec);
                ++numOfUnused[*i];
                vec.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        ret.clear();
        if ( nums.empty() ) return ret;

        for (int i : nums) {
            if (!numOfUnused.count(i))
                numOfUnused[i] = 1;
            else ++ numOfUnused[i];
        }

        unordered_set<int> uniqueNums (nums.begin(), nums.end());
        vector<int> tmp;
        tmp.clear();
        __permuteUnique(nums.size(), uniqueNums, 0, tmp);

        return ret;
    }
};