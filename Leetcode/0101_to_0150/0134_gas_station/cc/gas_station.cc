#include <vector>
using namespace std;

// 4 ms	9.2 MB. Greedy.
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int res = 0, tot = 0, curr = 0;
    for (int i = 0; i < gas.size(); ++i) {
      tot += gas[i] - cost[i];
      curr += gas[i] - cost[i];
      if (curr < 0) {
        curr = 0;
        res = i + 1;
      }
    }
    return tot >= 0 ? res : -1;
  }
};