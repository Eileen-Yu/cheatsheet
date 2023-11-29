// https://leetcode.com/problems/number-of-1-bits
// simple bit manipulation
class Solution {
public:
  int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
      // only when the least siginificant position = 1, would +1
      ans += n & 1;
      // shift to the right by 1 position
      n = n >> 1;
    }

    return ans;
  }
};
