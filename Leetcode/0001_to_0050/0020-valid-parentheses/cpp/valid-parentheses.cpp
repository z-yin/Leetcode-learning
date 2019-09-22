#include <stack>
#include <unordered_map>
using namespace std;

// 0 ms, 8.5 MB. Use switch to check valid pair
class Solution1 {
public:
    bool isValid(string s) {
        stack<char> stk;
        stk.emplace('#');
        
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.emplace(s[i++]);
            else {
                switch (s[i]) {
                    case ')':
                        if (stk.top() == '(') {
                            stk.pop();
                            ++ i;
                            break;
                        }
                        else return false;
                    case ']':
                        if (stk.top() == '[') {
                            stk.pop();
                            ++ i;
                            break;
                        }
                        else return false;
                    case '}':
                        if (stk.top() == '{') {
                            stk.pop();
                            ++ i;
                            break;
                        }
                        else return false;
                }
            }
        }
        return stk.top() == '#';
    }
};


// 4 ms, 8.6 MB. 
// Use unordered_map instead of switch syntax but got lower performance which may due to
// the optimization of switch (building a binary tree to separate condition) and also the
// construction time of an unordered_map.
class Solution2 {
public:
    bool isValid(string s) {
        stack<char> stk;
        stk.emplace('#');
        
        static unordered_map<char, char> validParen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.emplace(s[i++]);
            else {
                if (validParen[s[i]] == stk.top()) {
                    stk.pop();
                    ++ i;
                }
                else return false;
            }
        }
        return stk.top() == '#';
    }
};