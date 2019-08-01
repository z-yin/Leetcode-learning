#include <stack>
#include <set>

class Solution {
public:
    std::multiset<int> mSet;
    std::stack<int> s;
    
    void push(int value) {
        s.emplace(value);
        mSet.insert(value);
    }
    void pop() {
        int tmp = s.top();
        s.pop();
        mSet.erase(mSet.find(tmp));
    }
    int top() {
        return s.top();
    }
    int min() {
        return *mSet.begin();
    }
};