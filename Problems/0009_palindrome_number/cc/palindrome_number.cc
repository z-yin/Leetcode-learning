// 12 ms, 7.9 MB. Not using string. Reverse number.
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    return x == reverse(x);
  }

 private:
  long long reverse(int x) {
    long long rev_num = 0;
    while (x > 0) {
      rev_num = rev_num * 10 + x % 10;
      x /= 10;
    }
    return rev_num;
  }
};