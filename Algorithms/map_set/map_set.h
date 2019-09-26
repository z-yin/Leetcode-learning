//
// Created by Zhao Yin on 25/09/2019.
//

#ifndef TESTME_MAP_SET_H
#define TESTME_MAP_SET_H

template <typename K, typename V>
class Map {
 public:
  Map() = default;
  virtual ~Map() = default;
  virtual void push(const K &, const V &) = 0;
  virtual bool contains(const K &) const = 0;
  virtual V &at(const K &) const = 0;
  virtual V &operator[](const K &) const = 0;
  virtual V remove(const K &){};
  virtual int size() const = 0;
  virtual bool empty() const = 0;
  virtual void print() const = 0;
};

template <typename E>
class Set {
 public:
  Set() = default;
  virtual ~Set() = default;
  virtual void push(const E &) = 0;
  virtual bool contains(const E &) const = 0;
  virtual E remove(const E &){};
  virtual int size() const = 0;
  virtual bool empty() const = 0;
  virtual void print() const = 0;
};

#endif  // TESTME_MAP_SET_H
