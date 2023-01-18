// https://leetcode.com/problems/flip-string-to-monotone-increasing/description/

class Solution {
public:
  int minFlipsMonoIncr(string s) {
    int oneCnt = 0;
    int flip = 0;

    for (auto i : s) {
      // count the number of 1's so far
      if (i == '1')
        oneCnt++;

      else {
        // assume flip 0 to 1
        flip++;
        // whether to flip all 1's encounted or flip this 0
        flip = min(flip, oneCnt);
      }
    }

    return flip;
  }
};
