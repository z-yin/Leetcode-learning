//
// Created by Joy on 20/09/2019.
//

#ifndef ITERATIVE_COMPRESSION
#define ITERATIVE_COMPRESSION
#endif  // ITERATIVE_COMPRESSION

#ifndef TESTME_UNIONFIND_H
#define TESTME_UNIONFIND_H

#include <cassert>
using namespace std;

namespace UF {

class UnionFind {
 public:
  UnionFind(int count)
      : count_(count), parent_(new int[count_]), rank_(new int[count_]) {
    for (int i = 0; i < count; ++i) {
      parent_[i] = i;
      rank_[i] = 1;
    }
#if defined(ITERATIVE_COMPRESSION)
    cout << "ITERATIVE_COMPRESSION" << endl;
#else
    cout << "RECURSIVE_COMPRESSION" << endl;
#endif
  }

  ~UnionFind() {
    delete[] parent_;
    delete[] rank_;
  }

  int find(int p) {
    assert(p >= 0 && p < count_);
    // path compression
    // iterative
#if defined(ITERATIVE_COMPRESSION)
    while (p != parent_[p]) {
      parent_[p] = parent_[parent_[p]];
      p = parent_[p];
    }
    return p;
#else
    // recursive
    if (p != parent_[p]) {
      parent_[p] = find(parent_[p]);
    }
    return parent_[p];
#endif
  }

  bool isConnected(int p, int q) { return find(p) == find(q); }

  void unionElements(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if (pRoot == qRoot) return;
    if (rank_[pRoot] < rank_[qRoot]) {
      parent_[pRoot] = qRoot;
    } else if (rank_[pRoot] > rank_[qRoot]) {
      parent_[qRoot] = pRoot;
    } else {
      parent_[pRoot] = qRoot;
      ++rank_[qRoot];
    }
  }

 private:
  int count_;
  int *parent_;
  int *rank_;
};

}  // namespace UF

#endif  // TESTME_UNIONFIND_H
