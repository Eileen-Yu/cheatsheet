// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
// bit manipulation: each time retrieve the least siginificant bit, compare bit
// by bit, then right shift
class Solution {
public:
  int minBitFlips(int start, int goal) {
    int ans = 0;
    // if there remains bits to be manipulated
    while (start > 0 || goal > 0) {
      // retrieve the least significant bit
      int a = start & 1;
      int b = goal & 1;
      if (a != b)
        ans++;

      // continue by right shift
      start >>= 1;
      goal >>= 1;
    }

    return ans;
  }
};
