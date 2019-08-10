#include <vector>
using namespace std;


// 4 ms, 8,5 MB. Backtracking
class Solution {
private:
    vector<vector<int>> ret;
    
    void __combinationSum3 (const int& k, const int& n, int start, vector<int>& c, int sum) {
        
        if (sum == n && c.size() == k) {
            ret.emplace_back(c);
            return;
        }
        
        if (c.size() < k && sum < n) {
            for (int i = start; i < 10 && sum + i <= n; ++ i) {
                int rem = n - sum;
                int k_rem = k - c.size();
                if (rem < (i + k_rem - 1)*k_rem/2 || rem > (19 - k_rem)*k_rem/2) break;
                
                c.emplace_back(i);
                __combinationSum3(k, n, i + 1, c, sum + i);
                c.pop_back();
            }
        }
    } 
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        ret.clear();
        if (k <= 0 || n <= 0 || n < (k + 1)*k/2 || n > (19 - k)*k/2) return ret;
        
        vector<int> c;
        c.clear();
        __combinationSum3(k, n, 1, c, 0);
         
        return ret;
    }
};