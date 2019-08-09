#include <vector>
#include <string>
using namespace std;

// 0 ms, 8.3 MB
// similar to accumulator 
class Solution1 {
public:
    vector<string> letterCombinations(string digits) {
        if ( digits.empty() ) return vector<string> {};
        
        string a[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int N = digits.size();
        int *num = new int[N];  // upper bound of *curr
        int *curr = new int[N];
        vector<string> ret;
        
        for (int i = 0; i < N; ++i) {
            num[i] = a[digits[i] - '2'].size();
            curr[i] = 0;
        }
        
        while ( curr[N - 1] < num[N - 1] ) {
            string s = "";
            for (int i = 0; i < N; ++i)
                s += a[digits[i] - '2'][curr[i]];
            ret.emplace_back(s);
            
            ++curr[0];
            
            for (int i = 0; i < N - 1; ++i) {
                if (curr[i] < num[i])
                    break;
                else {
                    curr[i] = 0;
                    ++curr[i + 1];
                }
            }
        }
        return ret;
    }
};

// backtracking. 4 ms, 8.6 MB
class Solution2 {

private:
    vector<string> ret;
    const string letterMapping[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    void letterCombination (const string &digits, int index, const string &s) {

        if ( index == digits.size() ) {
            ret.emplace_back(s);
            return;
        }

        string letters = letterMapping[digits[index] - '2'];
        for (char letter : letters)
            letterCombination(digits, index + 1, s + letter);
    }

public:
    vector<string> letterCombinations(string digits) {
        ret.clear();
        if (digits.empty()) return ret;

        letterCombination(digits, 0, "");
        return ret;
    }
};