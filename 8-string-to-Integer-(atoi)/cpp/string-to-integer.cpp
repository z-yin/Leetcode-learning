// 8 ms, 8.2 MB
class Solution1 {
public:
    int myAtoi(string str) {
        int len = str.size();
        if ( len == 0 ) return 0;
        
        double res = 0;
        int positiveFlag = 1, startFlag = 0;
        for ( int i = 0; i < len; ++i ) {
            if ( str[i] >= '0' && str[i] <= '9' ) {
                startFlag = 1;
                res = res * 10 + (str[i] - '0');
                continue;
            }
            if ( res != 0 || startFlag) break;
            if ( str[i] == ' ' ) continue;
            if ( str[i] == '-' ) {
                positiveFlag = 0;
                startFlag = 1;
                continue;
            }
            if ( str[i] == '+' ) {
                startFlag = 1;
                continue;
            }
            else return 0;
        }
        
        if ( positiveFlag )
            return res > INT_MAX ? INT_MAX : res;
        return res < INT_MIN ? INT_MIN : -res;
    }
};

// 4 ms, 8.4 MB
class Solution2 {
public:
    int myAtoi(string str) {
        int len = str.size();
        if ( len == 0 ) return 0;
        
        double res = 0;
        int positiveFlag = 1, startFlag = 0;
        
        int i = 0;
        while (str[i] == ' ') ++i;
        
        if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-') return 0;
        if (str[i] == '+' || str[i] == '-') {
            
            if (i + 1 >= len || !isdigit(str[i + 1])) return 0;
            if (str[i] == '-') positiveFlag = 0;
            ++ i;
        }
        
        while ( isdigit(str[i]) ) {
            res = res*10 + (str[i++] - '0');
            if (res > INT_MAX) break;
        }
        
        if ( positiveFlag )
            return res > INT_MAX ? INT_MAX : res;
        return res < INT_MIN ? INT_MIN : -res;
    }
};