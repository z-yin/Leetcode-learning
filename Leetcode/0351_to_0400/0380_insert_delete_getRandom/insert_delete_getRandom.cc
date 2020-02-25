#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (index_map.count(val) == 0) {
      index_map[val] = vals.size();
      vals.emplace_back(val);
      return true;
    }
    return false;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (index_map.count(val) > 0) {
      int idx = index_map[val];
      vals[idx] = vals[vals.size() - 1];
      index_map[vals[vals.size() - 1]] = idx;
      vals.pop_back();
      index_map.erase(val);
      return true;
    }
    return false;
  }

  /** Get a random element from the set. */
  int getRandom() {
    int n = vals.size();
    int random = rand() % n;
    return vals[random];
  }

 private:
  unordered_map<int, int> index_map;
  vector<int> vals;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */