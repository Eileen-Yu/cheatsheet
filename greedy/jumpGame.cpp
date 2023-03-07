// https://leetcode.com/problems/jump-game/description/
// Greedy Algo:

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int farReach = 0;
    int len = nums.size();
    int currentReach, i;
    for (i = 0; i < len && i <= farReach; i++) {
      currentReach = i + nums[i];
      if (currentReach >= len - 1)
        return true;

      if (currentReach > farReach) {
        farReach = currentReach;
      }
    }
    return false;
  }
};
