#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

namespace solution_1 {

// 96 ms, 36 MB. Using link nodes and hashmap.
struct Node {
  unordered_map<char, Node *> nodes;
  bool end;
  Node() : end(false){};
};

class Trie {
 public:
  /** Initialize your data structure here. */
  Trie() { root = new Node(); }

  /** Inserts a word into the trie. */
  void insert(string word) {
    if (!search(word)) {
      Node *curr = root;
      for (const auto &c : word) {
        if (!curr->nodes.count(c)) {
          (curr->nodes)[c] = new Node();
        }
        curr = (curr->nodes)[c];
      }
      curr->end = true;
    }
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Node *curr = root;
    for (const auto &c : word) {
      if (!curr->nodes.count(c)) {
        return false;
      }
      curr = (curr->nodes)[c];
    }
    return curr->end;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Node *curr = root;
    for (const auto &c : prefix) {
      if (!curr->nodes.count(c)) {
        return false;
      }
      curr = (curr->nodes)[c];
    }
    return true;
  }

 private:
  Node *root;
};

}  // namespace solution_1

namespace solution_2 {

// 72 ms, 48.4 MB. Using link nodes and 26-entries array.
struct Node {
  vector<Node *> nodes;
  bool end;
  Node() : end(false), nodes(vector<Node *>(26, nullptr)) {}
};

class Trie {
 public:
  /** Initialize your data structure here. */
  Trie() { root = new Node(); }

  /** Inserts a word into the trie. */
  void insert(string word) {
    if (!search(word)) {
      Node *curr = root;
      for (const auto &c : word) {
        if (!(curr->nodes)[c - 'a']) {
          (curr->nodes)[c - 'a'] = new Node();
        }
        curr = (curr->nodes)[c - 'a'];
      }
      curr->end = true;
    }
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Node *curr = root;
    for (const auto &c : word) {
      if (!(curr->nodes)[c - 'a']) {
        return false;
      }
      curr = (curr->nodes)[c - 'a'];
    }
    return curr->end;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Node *curr = root;
    for (const auto &c : prefix) {
      if (!(curr->nodes)[c - 'a']) {
        return false;
      }
      curr = (curr->nodes)[c - 'a'];
    }
    return true;
  }

 private:
  Node *root;
};

}  // namespace solution_2