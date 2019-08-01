#include <vector>
#include <stack>

class Solution {
public:
    bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV) {
        int N = pushV.size();
        if (pushV.size() == 0) return false;
        
        std::stack<int> s;
        
        int i = 0, k = 0;
        while (i < N && k < N) {
            while (s.empty() || s.top() != popV[k]) {
                s.push(pushV[i++]);
            }
            while (!s.empty() && s.top() == popV[k]) {
                s.pop();
                k++;
            }
        }
        if (i == k) return true;
        else return false;
    }
};