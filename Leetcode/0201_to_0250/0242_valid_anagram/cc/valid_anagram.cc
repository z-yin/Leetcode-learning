#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 12 ms, 9.4 MB. Unordered_map. Hash.
class Solution1 {
 public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> cnt;
    for (char c : s) {
      ++cnt[c];
    }
    for (char c : t) {
      --cnt[c];
    }
    for (const auto& p : cnt) {
      if (p.second != 0) {
        return false;
      }
    }
    return true;
  }
};

// 8 ms, 9.5 MB. Array instead of map.
class Solution2 {
 public:
  bool isAnagram(string s, string t) {
    vector<int> cnt(26, 0);
    for (char c : s) {
      ++cnt[c - 'a'];
    }
    for (char c : t) {
      --cnt[c - 'a'];
    }
    for (int p : cnt) {
      if (p != 0) {
        return false;
      }
    }
    return true;
  }
};