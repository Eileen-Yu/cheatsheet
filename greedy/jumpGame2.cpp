
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
        // update the minimum step to the i+j-th node
        rslt[i + j] = min(rslt[i + j], rslt[i] + 1);
        /*
        if (rslt[i] + 1 < rslt[i + j]) {
          rslt[i + j] = rslt[i] + 1;
        }
        */
      }
    }
    return rslt[len - 1];
  }
};

// 2. greedy
class Solution {
public:
  int jump(vector<int> &nums) {
    // record the farest reachable node of one jump
    int maxFar = 0;
    // record the next starting point
    int end = 0;
    int ans = 0;

    // don't need to jump at the last node
    for (int i = 0; i < nums.size() - 1; i++) {
      maxFar = max(maxFar, i + nums[i]);
      // if (maxFar == nums.size() - 1) return ans+1;

      // need to jump another time
      if (i == end) {
        ans++;
        end = maxFar;
      }
    }

    return ans;
  }
};
