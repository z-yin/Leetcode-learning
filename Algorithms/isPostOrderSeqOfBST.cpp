#include <vector>
#include <queue>

class Solution {
public:
    struct TwoInt {
        int l;
        int r;
        TwoInt (int left, int right): l(left), r(right) {}
        int diff () {
            return r - l;
        }
    };
    
    bool VerifySquenceOfBST(std::vector<int> sequence) {
        int N = sequence.size();
        if (N == 0) return false;
        
        std::queue<TwoInt> q;
        q.emplace(TwoInt(0, N - 1));
        
        while (!q.empty()) {
            TwoInt curr = q.front();
            q.pop();
            if (curr.diff() < 2) continue;
            
            int root = sequence[curr.r];
            int leftEnd = 0;
            for (int i = curr.r - 1; i >= curr.l; --i) {
                if (!leftEnd && sequence[i] < root) leftEnd = i;
                if (leftEnd && sequence[i] > root) return false;
            }
            q.emplace(TwoInt(curr.l, leftEnd));
            q.emplace(TwoInt(leftEnd + 1, curr.r - 1));
        }
        return true;
    }
};