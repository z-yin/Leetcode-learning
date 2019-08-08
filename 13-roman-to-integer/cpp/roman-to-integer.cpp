#include <string>
using namespace std;

// 8 ms, 8.3 MB
// switch here is faster than using unordered_map
class Solution {
public:
    int romanCToInt (char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
    
    int romanToInt(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            
            if (i + 1 < s.size() && romanCToInt(s[i]) < romanCToInt(s[i + 1]))
                ret += romanCToInt(s[i + 1]) - romanCToInt(s[i++]);
            else ret += romanCToInt(s[i]);
        }
        return ret;
    }
};