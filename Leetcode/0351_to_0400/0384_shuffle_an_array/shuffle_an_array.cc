#include <vector>
using namespace std;

class Solution {
 public:
  Solution(vector<int>& nums) {
    orig = nums;
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return orig;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> res(orig);
    for (int i = res.size(); i > 0; --i) {
      int random = rand() % i;
      swap(res[random], res[i - 1]);
    }
    return res;
  }
  
 private:
  vector<int> orig;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */