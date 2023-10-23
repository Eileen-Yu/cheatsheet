// https://leetcode.com/problems/power-of-four/description
// 1. loop
class Solution {
public:
  bool isPowerOfFour(int n) {
    // special case:
    if (n == 1)
      return true;
    if (n <= 0)
      return false;

    // main logic
    while (n > 1) {
      if (n % 4 != 0)
        return false;
      n /= 4;
    }

    return true;
  }
};

// 2. recursion
class Solution {
public:
  bool isPowerOfFour(int n) {
    // when to return
    if (n == 1)
      return true;

    if (n <= 0 || n % 4 != 0)
      return false;

    // else, continue to check
    return isPowerOfFour(n / 4);
  }
};
