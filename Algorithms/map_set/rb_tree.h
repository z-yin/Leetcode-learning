//
// Created by Zhao Yin on 25/09/2019.
//

#ifndef TESTME_RB_TREE_H
#define TESTME_RB_TREE_H

#include "map_set.h"

namespace rb {

typedef bool color_type;
const color_type RED = false;
const color_type BLACK = true;

template <typename K, typename V>
struct Node {
  K key;
  V value;
  Node *left;
  Node *right;
  color_type color;
  Node(const K &key, const V &value)
      : key(key), value(value), left(nullptr), right(nullptr), color(RED) {}
};

template <typename K, typename V>
class RBTree {
 public:
  typedef Node<K, V> t_node;

 public:
  RBTree() : root_(nullptr), size_(0) {}

  ~RBTree() { delete root_; }

  int size() const { return size_; }

  bool empty() const { return size_ == 0; }

  void push(const K &key, const V &value) {
    root_ = push(root_, key, value);
    root_->color = BLACK;
  }

  t_node *find(const K &key) const { return find(root_, key); }

  bool contains(const K &key) const { return find(key) != nullptr; }

  V &at(const K &key) const {
    t_node *node = find(key);
    if (node == nullptr) throw std::out_of_range("Key doesn't exist!");
    return node->value;
  }

  V &operator[](const K &key) const { return at(key); }

  t_node *min() const {
    if (size_ == 0) throw std::length_error("The tree is empty!");
    return min(root_);
  }

  t_node *max() const {
    if (size_ == 0) throw std::length_error("The tree is empty!");
    return max(root_);
  }

  bool isBST() const {
    std::vector<int> keys;
    inOrder(root_, keys);
    for (size_t i = 1; i < keys.size(); ++i)
      if (keys[i - 1] > keys[i]) return false;
    return true;
  }

  // Level print
  void print() const {
    if (root_) {
      // Create an empty queue for level order traversal
      std::queue<t_node *> q;
      q.push(root_);
      t_node *curr;

      while (!q.empty()) {
        curr = q.front();
        q.pop();
        std::cout << curr->key << ": " << curr->value << " ";

        /* Enqueue left child */
        if (curr->left) q.emplace(curr->left);
        /* Enqueue left child */
        if (curr->right) q.emplace(curr->right);
      }
    }
    std::cout << std::endl;
  }

 private:
  t_node *root_;
  int size_;

  bool isRed(t_node *node) const {
    if (node == nullptr) return false;
    return node->color == RED;
  }

  /**
   *   node                     x
   *   /   \     左旋转         /  \
   *  t1   x   --------->   node   t3
   *      / \              /   \
   *     t2 t3            t1   t2
   */
  t_node *leftRotate(t_node *node) {
    t_node *x = node->right;
    node->right = x->left;
    x->left = node;

    x->color = node->color;
    node->color = RED;
    return x;
  }

  void flipColors(t_node *node) {
    node->color = RED;
    node->left->color = BLACK;
    node->right->color = BLACK;
  }

  /**
   *     node                   x
   *     /   \     右旋转       /  \
   *    x    t2   ------->   y   node
   *   / \                       /  \
   *  y  t1                     t1  t2
   */
  t_node *rightRotate(t_node *node) {
    t_node *x = node->left;
    node->left = x->right;
    x->right = node;

    x->color = node->color;
    node->color = RED;

    return x;
  }

  t_node *push(t_node *node, const K &key, const V &value) {
    if (node == nullptr) {
      ++size_;
      return new t_node(key, value);
    }

    if (key < node->key)
      node->left = push(node->left, key, value);
    else if (key > node->key)
      node->right = push(node->right, key, value);
    else
      node->value = value;

    if (isRed(node->right) && !isRed(node->left)) node = leftRotate(node);
    if (isRed(node->left) && isRed(node->left->left)) node = rightRotate(node);
    if (isRed(node->left) && isRed(node->right)) flipColors(node);

    return node;
  }

  t_node *find(t_node *node, const K &key) const {
    if (node == nullptr) return nullptr;

    if (node->key == key)
      return node;
    else if (key < node->key)
      return find(node->left, key);
    else
      return find(node->right, key);
  }

  t_node *min(t_node *node) const {
    if (node->left == nullptr) return node;
    return min(node->left);
  }

  t_node *max(t_node *node) const {
    if (node->right == nullptr) return node;
    return max(node->right);
  }

  void inOrder(t_node *node, std::vector<int> &keys) const {
    if (node) {
      // stack to store the future node that will be accessed
      std::stack<t_node *> s;
      // current node
      t_node *curr = node;
      while (curr || !s.empty()) {
        // find the most left node of a "root" node and store the "root"
        while (curr) {
          s.push(curr);
          curr = curr->left;
        }
        curr = s.top();
        s.pop();
        keys.emplace_back(curr->key);
        curr = curr->right;
      }
    }
  }

  bool isBalanced(t_node *node) const {
    if (node == nullptr) return true;

    int balance_factor = balanceFactor(node);
    if (abs(balance_factor) > 1) return false;

    return isBalanced(node->left) && isBalanced(node->right);
  }
};

template <typename K, typename V>
class RBMap : public Map<K, V> {
 public:
  RBMap() = default;
  ~RBMap() = default;
  void push(const K &key, const V &value) { rb_tree_.push(key, value); }
  typename RBTree<K, V>::t_node *find(const K &key) {
    return rb_tree_.find(key);
  }
  bool contains(const K &key) const { return rb_tree_.contains(key); }
  V &at(const K &key) const { return rb_tree_.at(key); }
  V &operator[](const K &key) const { return rb_tree_.at(key); }
  //  V remove(const K &key) { return rb_tree_.remove(key); }
  typename RBTree<K, V>::t_node *min() const { return rb_tree_.min(); }
  typename RBTree<K, V>::t_node *max() const { return rb_tree_.max(); }
  int size() const { return rb_tree_.size(); }
  bool empty() const { return rb_tree_.empty(); }
  void print() const { rb_tree_.print(); }
  bool isBST() const { return rb_tree_.isBST(); }
  bool isBalanced() const { return rb_tree_.isBalanced(); }

 private:
  RBTree<K, V> rb_tree_;
};

template <typename E>
class RBSet : public Set<E> {
 public:
  RBSet() = default;
  ~RBSet() = default;
  void push(const E &e) { rb_tree_.push(e, e); }
  bool contains(const E &e) const { return rb_tree_.contains(e); }
  //  E remove(const E &e) { return rb_tree_.remove(e); }
  E &min() const { return rb_tree_.min()->key; }
  E &max() const { return rb_tree_.max()->key; }
  int size() const { return rb_tree_.size(); }
  bool empty() const { return rb_tree_.empty(); }
  void print() const { rb_tree_.print(); }
  bool isBST() const { return rb_tree_.isBST(); }
  bool isBalanced() const { return rb_tree_.isBalanced(); }

 private:
  RBTree<E, E> rb_tree_;
};

}  // namespace rb

#endif  // TESTME_RB_TREE_H
