#include <vector>
#include <string>
using namespace std;

// 4 ms, 9 MB. Backtracking
class Solution {
private:
    vector<string> ret;
    const int tm[10] = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};

    void __readBinaryWatch (int num, int remain, int start, int h, int m) {
        if (remain == 0) {
            string s = to_string(h) + ':';
            if (m > 9) s += to_string(m);
            else s += '0' + to_string(m);
            ret.emplace_back(s);
            return;
        }

        // [start...10 - remain)
        for (int i = start; i < 10 - remain + 1; ++ i) {
            if (i < 4 && (h + tm[i] > 11)) {
                i = 3;
                continue;
            }
            if (i >= 4 && (m + tm[i] > 59)) break;
            if (i < 4)
                __readBinaryWatch(num, remain - 1, i + 1, h + tm[i], m);
            else __readBinaryWatch(num, remain - 1, i + 1, h, m + tm[i]);
        }
    }
public:
    vector<string> readBinaryWatch(int num) {

        ret.clear();
        if (num == 0) return vector<string>{"0:00"};

        __readBinaryWatch(num, num, 0, 0, 0);
        return ret;
    }
};