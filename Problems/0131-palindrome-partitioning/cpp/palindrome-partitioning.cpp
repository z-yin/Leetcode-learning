#include <vector>
#include <string>
using namespace std;

// 12 ms, 13.4 MB. Backtracking
class Solution {
private:
    vector<vector<string>> ret;

    bool __isPalin (const string &str, int left, int right) {
        while (left < right)
            if (str[left++] != str[right--])
                return false;
        return true;
    }

    void __partition (const string &str, int start, vector<string> &s) {
        
        if (start == str.size()) {
            ret.emplace_back(s);
            return;
        }

        int i = 1; // number of characters used
        while (start + i <= str.size()) {
            if (__isPalin(str, start, start + i - 1)) {
                s.emplace_back( str.substr(start, i) );
                __partition(str, start + i, s);
                s.pop_back();
            }
            ++ i;
        }
    }
public:
    vector<vector<string>> partition(string s) {

        ret.clear();
        if (s.empty()) return ret;

        vector<string> tmp;
        tmp.clear();
        __partition(s, 0, tmp);
        return ret;
    }
};