#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int N = A.size();
    vector<int> x(N * N, 0), y(N * N, 0);
    
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        x[N * i + j] = A[i] + B[j];
      }
    }
    
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        y[N * i + j] = C[i] + D[j];
      }
    }
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    int count = 0;
    int i = 0, j = x.size() - 1;
    while (i < x.size() && j >= 0) {
      int sum = x[i] + y[j];
      if (sum == 0) {
        int ii = i + 1;
        int jj = j - 1;
        while (ii < x.size() && x[ii] == x[ii - 1]) ++ii;
        while (jj >= 0 && y[jj] == y[jj + 1]) --jj;
        count += (ii - i) * (j - jj);
        i = ii;
        j = jj + 1;
      } else if (sum < 0) {
        ++i;
      } else {
        --j;
      }
    }
    return count;
  }
};