#include <queue>
#include <vector>
#include <iostream>
using namespace std;

// 60 ms, 11.9 MB. Min-heap.
struct Element {
  int val;
  int row;
  int col;
  Element(int v, int r, int c) : val(v), row(r), col(c) {}
};

bool operator<(const Element &e1, const Element &e2) { return e1.val > e2.val; }

class Solution1 {
 public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    priority_queue<Element> hp;
    for (int i = 0; i < matrix.size(); ++i) {
      hp.emplace(Element(matrix[i][0], i, 0));
    }
    for (int i = 1; i < k; ++i) {
      int row = hp.top().row;
      int col = hp.top().col;
      hp.pop();
      if (col == matrix.size() - 1) {
        hp.emplace(Element(INT_MAX, row, -1));
      } else {
        hp.emplace(Element(matrix[row][col + 1], row, col + 1));
      }
    }
    return hp.top().val;
  }
};

// 40 ms, 11.7 MB. Binary search. Sorted matrix search.
class Solution2 {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int N = matrix.size();
    int lower = matrix[0][0];
    int upper = matrix[N - 1][N - 1];
    while (lower < upper) {
      int mid = (lower + upper) / 2;
      int rk = rank(matrix, mid);
      if (rk < k) {
        lower = mid + 1;
      } else {
        upper = mid;
      }
    }
    return upper;
  }
  
  int rank(const vector<vector<int>>& matrix, int target) {
    int M = matrix.size();
    int N = matrix[0].size();
    int i = M - 1;
    int j = 0;
    int cnt = 0;
    while (i >= 0 && j < N) {
      if (target >= matrix[i][j]) {
        cnt += i + 1;
        ++j;
      } else {
        --i;
      }
    }
    return cnt;
  }
};

// 12 ms, 11.8 MB. Binary search. Sorted matrix search.
class Solution3 {
 public:
  Solution3(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int N = matrix.size();
    int lower = matrix[0][0];
    int upper = matrix[N - 1][N - 1];
    while (lower < upper) {
      int mid = (lower + upper) / 2;
      int rk = rank(matrix, mid);
      if (rk < k) {
        lower = mid + 1;
      } else {
        upper = mid;
      }
    }
    return upper;
  }
  
  int rank(const vector<vector<int>>& matrix, int target) {
    int M = matrix.size();
    int N = matrix[0].size();
    int i = M - 1;
    int j = 0;
    int cnt = 0;
    while (i >= 0 && j < N) {
      if (target >= matrix[i][j]) {
        cnt += i + 1;
        ++j;
      } else {
        --i;
      }
    }
    return cnt;
  }
};