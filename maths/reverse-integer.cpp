// https://leetcode.com/problems/reverse-integer
// basic skill: reverse a integer
class Solution {
public:
  int reverse(int x) {
    // the tmp num after reverse part of the original x
    int r = 0;

    while (x) {
      // out of int range
      if (r > INT_MAX / 10 || r < INT_MIN / 10)
        return 0;

      // move the tmp num to left, add the least significant of this time
      r = r * 10 + x % 10;
      // deal with the left digits
      x /= 10;
    }

    return r;
  }
};
