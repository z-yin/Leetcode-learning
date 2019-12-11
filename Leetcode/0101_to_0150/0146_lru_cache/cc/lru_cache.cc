#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

// 100 ms	37.9 MB.
// list<pair<int, int>>
// unordered_map<int, list<pair<int, int>>::iterator>
class LRUCache {
 public:
  list<pair<int, int>> l;
  unordered_map<int, list<pair<int, int>>::iterator> mp;
  int cap;

  LRUCache(int capacity) { cap = capacity; }

  int get(int key) {
    if (!mp.count(key)) return -1;
    auto it = mp[key];
    if (it == l.begin()) return (*it).second;
    l.splice(l.cbegin(), l, it);
    return (*it).second;
  }

  void put(int key, int value) {
    if (mp.count(key)) {  // replace duplicate
      auto it = mp[key];
      if (it != l.begin()) l.splice(l.cbegin(), l, it);
      (*it).second = value;
    } else {
      l.emplace_front(pair<int, int>(key, value));
      mp[key] = l.begin();
      if (l.size() > cap) {
        int k = l.back().first;
        mp.erase(k);
        l.pop_back();
      }
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */