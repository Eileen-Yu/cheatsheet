// https://leetcode.com/problems/counting-bits/
// bit manipulation trick: n & (n-1)
// 1. always eliminate the least significant 1
// 2. this can help to check if n is 2^n (if == 0)
class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> ans;

    // loop from 0 ~ n
    for (int i = 0; i < n + 1; i++) {
      // count for number of 1's
      int count = 0;
      // avoid pollute the original i, that would affect the loop
      int tmp = i;

      while (tmp) {
        // bit manipulation
        // this would always eliminate the least significant 1
        tmp = tmp & (tmp - 1);
        count++;
      }

      ans.push_back(count);
    }

    return ans;
  }
};
