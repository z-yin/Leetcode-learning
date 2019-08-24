#include <algorithm>
#include <vector>
using namespace std;

// 8 ms, 9.2 MB. Use heapsort and only sort the largest N items
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    if (nums.size() == 1) return nums[0];
    heapSort(nums, k);
    return nums[nums.size() - k];
  }

 private:
  void shiftDown(vector<int>& nums, int n, int i) {
    int e = nums[i];
    while (2 * i + 1 < n) {
      int j = 2 * i + 1;
      if (j + 1 < n && nums[j + 1] > nums[j]) {
        ++j;
      }
      if (nums[j] <= e) break;
      nums[i] = nums[j];
      i = j;
    }
    nums[i] = e;
  }

  void heapSort(vector<int>& nums, int k) {
    for (int i = nums.size() / 2 - 1; i >= 0; --i) {
      shiftDown(nums, nums.size(), i);
    }
    int smallest = max((int)nums.size() - k, 1);
    for (int i = nums.size() - 1; i >= smallest; --i) {
      swap(nums[0], nums[i]);
      shiftDown(nums, i, 0);
    }
  }
};