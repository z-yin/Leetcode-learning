#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> ret;

    void __letterCasePermutation (const string &str, int index, const string &s) {

        if ( index == str.size() ) {
            ret.emplace_back(s);
            return;
        }

        if ( isdigit(str[index]) )
            __letterCasePermutation(str, index + 1, s + str[index]);
        else {
            __letterCasePermutation(str, index + 1, s + (char)tolower(str[index]));
            __letterCasePermutation(str, index + 1, s + (char)toupper(str[index]));
        }
    }
public:
    vector<string> letterCasePermutation(string S) {

        ret.clear();
        if ( S.empty() ) return ret;

        __letterCasePermutation(S, 0, "");

        return ret;
    }
};