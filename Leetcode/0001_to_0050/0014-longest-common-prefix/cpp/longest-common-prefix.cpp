#include <string>
using namespace std;

// 4 ms, 9 MB
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        if (strs.size() == 0) return "";
        
        int i = 0;
        string ret = "";
        while (1) {
            char c;
            if (i >= strs[0].size()) return ret;
            c = strs[0][i];
            for (int k = 1; k < strs.size(); ++k) {
                if (i > strs[k].size()) return ret;
                if (strs[k][i] != c)
                    return ret;
            }
            ret += c;
            ++ i;
        }
        return ret;
    }
};