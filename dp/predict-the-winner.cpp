// https://leetcode.com/problems/predict-the-winner/description/
// 1. recursion
class Solution {
public:
  // return how much more score player A can get than player B
  int recursion(int i, int j, vector<int> &nums, bool turn) {
    // when to return
    if (i > j || i == nums.size() || j == -1)
      return 0;

    // if it's player A's turn, let A try to get maximum score
    if (turn == true) {
      // if pick the first element / last element
      return max(nums[i] + recursion(i + 1, j, nums, false),
                 nums[j] + recursion(i, j - 1, nums, false));
    } else { // if it's player B's turn, B also play optimally, so need to
             // return the minimum
      // if pick the first element / last element
      return min(-nums[i] + recursion(i + 1, j, nums, true),
                 -nums[j] + recursion(i, j - 1, nums, true));
    }
  }

  bool PredictTheWinner(vector<int> &nums) {
    int n = nums.size();

    int score = recursion(0, n - 1, nums, true);
    return score >= 0;
  }
};
