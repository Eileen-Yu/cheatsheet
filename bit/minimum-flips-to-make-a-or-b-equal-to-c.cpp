// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
// bit manipulation
class Solution {
public:
  int minFlips(int a, int b, int c) {
    int ans = 0;
    // if any one is not 0, means we need to manipulate
    while (a > 0 || b > 0 || c > 0) {
      // retrieve the last bit of a,b,c
      int bitA = a & 1;
      int bitB = b & 1;
      int bitC = c & 1;

      // if bitC is 0, both of bitA and bitB should be 0
      // so here we just count those should flip from 1 to 0
      if (bitC == 0)
        ans += bitA + bitB;

      // if bitC != 0, either bitA or bitB should be 1
      // so if both of them are 0, need to flip one of them
      else {
        if (bitA == 0 && bitB == 0)
          ans += 1;
      }

      // move to the next bit
      a >>= 1;
      b >>= 1;
      c >>= 1;
    }

    return ans;
  }
};
