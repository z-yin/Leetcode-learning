#include <vector>
using namespace std;

// 8 ms, 17.1 MB
class Solution {
private:
    vector<string> ret;

    void __generateParenthesis(int numLeft, int index, int open_brace, string s) {
        if (numLeft == 0) {
            while (open_brace--) {
                s += ')';
            }
            ret.emplace_back(s);
            return;
        }

        __generateParenthesis(numLeft - 1, index + 1, open_brace + 1, s + '(');
        if (open_brace > 0)
            __generateParenthesis(numLeft, index + 1, open_brace - 1, s + ')');
    }
public:
    vector<string> generateParenthesis(int n) {
        ret.clear();
        if (n == 0) return ret;

        __generateParenthesis(n, 0, 0,  "");
        return ret;
    }
};