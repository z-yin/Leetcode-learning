#include <vector>
using namespace std;


// 60 ms, 12.7 MB. Backtracking
class Solution {
private:
    vector<vector<int>> ret;
    
    void __combine (const int& n, int k, int index, vector<int>& vec) {
        
        if (vec.size() == k) {
            ret.emplace_back(vec);
            return;
        }
        
        for (int i = index; i <= n - (k-vec.size()) + 1; ++ i) {
            vec.emplace_back(i);
            __combine(n, k, i + 1, vec);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        
        ret.clear();
        if (n <= 0 || n < k || k < 1) return ret;
        
        vector<int> tmp;
        tmp.clear();
        __combine(n, k, 1, tmp);
        
        return ret;
    }
};