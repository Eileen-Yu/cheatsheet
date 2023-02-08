
// https://leetcode.com/problems/jump-game-ii/description/
// 1. dp
class Solution {
public:
  int jump(vector<int> &nums) {

    int len = nums.size();
    // record the minimum step to the i-th node
    vector<int> rslt(len, INT_MAX - 1);
    rslt[0] = 0;

    // loop every node
    for (int i = 0; i < len; i++) {
      // loop each node that is reachable
      for (int j = 0; j <= nums[i]; j++) {
        // already reach the last one
        if (i + j >= len)
          return rslt[len - 1];
        // the minimum step to the i+j-th node
        if (rslt[i] + 1 < rslt[i + j]) {
          rslt[i + j] = rslt[i] + 1;
        }
      }
    }
    return rslt[len - 1];
  }
};
