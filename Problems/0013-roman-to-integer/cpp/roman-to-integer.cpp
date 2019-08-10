#include <string>
using namespace std;

// 8 ms, 8.3 MB
// switch here is faster than using unordered_map
class Solution1 {
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


// 8 ms, 8.3 MB
class Solution2 {
public:
    int romanToInt(string s) {
        int arr[26]; // tricky
        arr['I' - 'A'] = 1;
        arr['V' - 'A'] = 5;
        arr['X' - 'A'] = 10;
        arr['L' - 'A'] = 50;
        arr['C' - 'A'] = 100;
        arr['D' - 'A'] = 500;
        arr['M' - 'A'] = 1000;
        
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && arr[s[i]-'A'] < arr[s[i + 1]-'A'])
                ret += arr[s[i + 1]-'A'] - arr[s[i++]-'A'];
            else ret += arr[s[i]-'A'];
        }
        return ret;
    }
};