#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 88 ms, 38.4 MB. Trie.
class WordDictionary {
 public:
  /** Initialize your data structure here. */
  WordDictionary() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    root = new Node();
  }

  /** Adds a word into the data structure. */
  void addWord(const string &word) {
    Node *curr = root;
    for (const auto &c : word) {
      if (!curr->nodes_.count(c)) {
        (curr->nodes_)[c] = new Node();
      }
      curr = (curr->nodes_)[c];
    }
    curr->end = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(const string &word) {
    Node *curr = root;
    return search(word, curr, 0);
  }

 private:
  class Node {
   public:
    unordered_map<char, Node *> nodes_;
    bool end;
    Node() : end(false){};
  };

  Node *root;

  bool search(const string &word, Node *node, int index) {
    if (index == word.size() && node->end) return true;
    if (word[index] != '.') {
      if (!node->nodes_.count(word[index])) return false;
      return search(word, (node->nodes_)[word[index]], index + 1);
    } else {
      for (const auto &pair : node->nodes_) {
        if (search(word, pair.second, index + 1)) return true;
      }
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */