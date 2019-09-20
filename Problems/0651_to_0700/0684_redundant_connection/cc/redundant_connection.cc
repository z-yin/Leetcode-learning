#include <vector>
using namespace std;

// 4 ms, 9.6 MB. Union find.
class UnionFind {
 public:
  UnionFind(int N) : N_(N), parent_(new int[N]) {
    for (int i = 0; i < N; ++i) parent_[i] = i;
  }

  ~UnionFind() { delete[] parent_; }

  int find(int p) {
    while (p != parent_[p]) {
      parent_[p] = parent_[parent_[p]];
      p = parent_[p];
    }
    return p;
  }

  bool unionElements(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if (pRoot == qRoot) return true;  // cicle created
    if (pRoot > qRoot) {
      parent_[pRoot] = qRoot;
    } else {
      parent_[qRoot] = pRoot;
    }
    return false;
  }

 private:
  int N_;
  int* parent_;
};

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UnionFind uf(edges.size());
    int i;
    for (i = 0; i < edges.size(); ++i) {
      if (uf.unionElements(edges[i][0] - 1, edges[i][1] - 1)) break;
    }
    return edges[i];
  }
};