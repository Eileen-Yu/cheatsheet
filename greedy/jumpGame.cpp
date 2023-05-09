// https://leetcode.com/problems/jump-game/description/
// Greedy Algo:
// loop the array, every time record the farest idx we can reach as the loop
// limitation then in this limited range, check if we can reach the last idx

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    // record when we start from certain idx, which idx can we reach
    int currentReach = 0;
    // record the most far idx we can reach till now
    int farReach = 0;

    // loop every idx
    // use the farReach to restrict the loop limitation
    for (int i = 0; i <= farReach && i < n; i++) {
      // to which idx we can reach from i
      currentReach = i + nums[i];
      // we can reach the last idx
      if (currentReach >= n - 1)
        return true;
      // else we need to check for the next one
      else
        farReach = max(farReach, currentReach);
    }

    return false;
  }
};
