#include <algorithm>
#include <vector>
using namespace std;

// 4 ms, 9.6 MB
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int length = triangle.size();
    if (length == 0) return 0;
    if (length == 1) return triangle[0][0];

    // vector<vector<int>> memo (triangle);
    for (int i = 1; i < length; ++i) {
      for (int j = 0; j < triangle[i].size(); ++j) {
        if (j == 0)
          triangle[i][j] += triangle[i - 1][j];
        else if (j == triangle[i].size() - 1)
          triangle[i][j] += triangle[i - 1][j - 1];
        else
          triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
      }
    }
    return *min_element(triangle[length - 1].begin(),
                        triangle[length - 1].end());
  }
};