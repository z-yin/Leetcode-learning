//
// Created by Zhao Yin on 24/09/2019.
//

#ifndef TESTME_AVL_H
#define TESTME_AVL_H

#include <algorithm>
#include <exception>
#include <queue>
#include <stack>
#include "map_set.h"

namespace avl {

template <typename K, typename V>
struct Node {
  K key;
  V value;
  Node *left, *right;
  int height;  // use a method wrapper to retrieve

  Node(const K &key, const V &value)
      : key(key), value(value), left(nullptr), right(nullptr), height(1) {}
};

template <typename K, typename V>
class AVLTree {
 public:
  typedef Node<K, V> t_node;

 public:
  AVLTree() : root_(nullptr), size_(0) {}

  ~AVLTree() { delete root_; }

  int size() const { return size_; }

  bool empty() const { return size_ == 0; }

  void push(const K &key, const V &value) { root_ = push(root_, key, value); }

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

  V remove(const K &key) {
    V &v = at(key);
    root_ = remove(root_, key);
    return v;
  }

  bool isBST() const {
    std::vector<int> keys;
    inOrder(root_, keys);
    for (size_t i = 1; i < keys.size(); ++i)
      if (keys[i - 1] > keys[i]) return false;
    return true;
  }

  bool isBalanced() const { return isBalanced(root_); }

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

  int height(t_node *node) const { return node ? node->height : 0; }

  int balanceFactor(t_node *node) const {
    return node ? (height(node->left) - height(node->right)) : 0;
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

    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance_factor = balanceFactor(node);

    // balance maintain
    // LL
    if (balance_factor > 1 && balanceFactor(node->left) >= 0)
      return rightRotate(node);
    // RR
    if (balance_factor < -1 && balanceFactor(node->right) <= 0)
      return leftRotate(node);
    // LR
    if (balance_factor > 1 && balanceFactor(node->left) < 0) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
    // RL
    if (balance_factor < -1 && balanceFactor(node->right) > 0) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }

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

  t_node *remove(t_node *node, const K &key) {
    if (node == nullptr) return nullptr;

    t_node *ret_node;
    if (key < node->value) {
      node->left = remove(node->left, key);
      ret_node = node;

    } else if (key > node->value) {
      node->right = remove(node->right, key);
      ret_node = node;

    } else {
      if (node->right == nullptr) {
        t_node *left = node->left;
        node->left = nullptr;
        --size_;
        ret_node = left;

      } else if (node->left == nullptr) {
        t_node *right = node->right;
        --size_;
        ret_node = right;

      } else {
        t_node *successor = min(node->right);
        successor->right = remove(node->right, successor->key);
        successor->left = node->left;
        node->left = node->right = nullptr;
        ret_node = successor;
      }
    }

    if (ret_node == nullptr) return nullptr;

    ret_node->height =
        1 + std::max(height(ret_node->left), height(ret_node->right));
    int balance_factor = balanceFactor(ret_node);

    // balance maintain
    // LL
    if (balance_factor > 1 && balanceFactor(ret_node->left) >= 0)
      return rightRotate(ret_node);
    // RR
    if (balance_factor < -1 && balanceFactor(ret_node->right) <= 0)
      return leftRotate(ret_node);
    // LR
    if (balance_factor > 1 && balanceFactor(ret_node->left) < 0) {
      ret_node->left = leftRotate(ret_node->left);
      return rightRotate(ret_node);
    }
    // RL
    if (balance_factor < -1 && balanceFactor(ret_node->right) > 0) {
      ret_node->right = rightRotate(ret_node->right);
      return leftRotate(ret_node);
    }

    return ret_node;
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

  /**
   * 对节点y进行向右旋转操作，返回旋转后新的根节点x
   *        y                              x
   *       / \                           /   \
   *      x   t4     向右旋转 (y)        z     y
   *     / \       - - - - - - - ->    / \   / \
   *    z   t3                       t1  t2 t3 t4
   *   / \
   * t1   t2
   */
  t_node *rightRotate(t_node *y) {
    t_node *x = y->left;
    t_node *t3 = x->right;

    x->right = y;
    y->left = t3;

    y->height = 1 + std::max(height(y->left), height(y->right));
    x->height = 1 + std::max(height(x->left), height(x->right));
    return x;
  }

  /**
   * 对节点y进行向左旋转操作，返回旋转后新的根节点x
   *    y                             x
   *  /  \                          /   \
   * t1   x      向左旋转 (y)       y     z
   *     / \   - - - - - - - ->   / \   / \
   *   t2  z                     t1 t2 t3 t4
   *      / \
   *     t3 t4
   */
  t_node *leftRotate(t_node *y) {
    t_node *x = y->right;
    t_node *t2 = x->left;

    x->left = y;
    y->right = t2;

    y->height = 1 + std::max(height(y->left), height(y->right));
    x->height = 1 + std::max(height(x->left), height(x->right));
    return x;
  }
};

template <typename K, typename V>
class AVLMap : public Map<K, V> {
 public:
  AVLMap() = default;
  ~AVLMap() = default;
  void push(const K &key, const V &value) { avl_tree_.push(key, value); }
  typename AVLTree<K, V>::t_node *find(const K &key) {
    return avl_tree_.find(key);
  }
  bool contains(const K &key) const { return avl_tree_.contains(key); }
  V &at(const K &key) const { return avl_tree_.at(key); }
  V &operator[](const K &key) const { return avl_tree_.at(key); }
  V remove(const K &key) { return avl_tree_.remove(key); }
  typename AVLTree<K, V>::t_node *min() const { return avl_tree_.min(); }
  typename AVLTree<K, V>::t_node *max() const { return avl_tree_.max(); }
  int size() const { return avl_tree_.size(); }
  bool empty() const { return avl_tree_.empty(); }
  void print() const { avl_tree_.print(); }
  bool isBST() const { return avl_tree_.isBST(); }
  bool isBalanced() const { return avl_tree_.isBalanced(); }

 private:
  AVLTree<K, V> avl_tree_;
};

template <typename E>
class AVLSet : public Set<E> {
 public:
  AVLSet() = default;
  ~AVLSet() = default;
  void push(const E &e) { avl_tree_.push(e, e); }
  bool contains(const E &e) const { return avl_tree_.contains(e); }
  E remove(const E &e) { return avl_tree_.remove(e); }
  E &min() const { return avl_tree_.min()->key; }
  E &max() const { return avl_tree_.max()->key; }
  int size() const { return avl_tree_.size(); }
  bool empty() const { return avl_tree_.empty(); }
  void print() const { avl_tree_.print(); }
  bool isBST() const { return avl_tree_.isBST(); }
  bool isBalanced() const { return avl_tree_.isBalanced(); }

 private:
  AVLTree<E, E> avl_tree_;
};

}  // namespace avl

#endif  // TESTME_AVL_H
