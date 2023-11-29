// a modification to count number of 1's in the bit representation:
// https://leetcode.com/problems/number-of-1-bits
class Solution {
public:
  int hammingWeight(uint32_t n) {
    int ans = 0;

    // needs to loop 32 times
    // otherwise for example: 00000000000000000000000000001011
    // we need to take the leading 0's into account
    for (int i = 0; i < 32; i++) {
      // only when the least siginificant position = 0, would +1
      // In C++, == has higher precedence than &, so need ()
      if ((n & 1) == 0)
        ans++;
      // shift to the right by 1 position
      n = n >> 1;
    }

    return ans;
  }
}
