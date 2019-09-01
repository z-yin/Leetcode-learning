#include <stack>
using namespace std;

// 0 ms, 8.8 MB. Using two stacks.
class MyQueue {
 public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { in_.emplace(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int ret = peek();
    out_.pop();
    return ret;
  }

  /** Get the front element. */
  int peek() {
    if (out_.empty()) {
      while (!in_.empty()) {
        out_.emplace(in_.top());
        in_.pop();
      }
    }
    return out_.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return in_.empty() && out_.empty(); }

 private:
  stack<int> in_;
  stack<int> out_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */