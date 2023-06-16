// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/
// Pascal triangle (dp + tabulation) to record the permutation for filling the
// element positons + divide & conquer (recursion) to divide the BST into left &
// right
class Solution {
public:
  // dp[i][j] represents how many ways we can pick j elements from i elements
  vector<vector<long long int>> dp;
  long long mod = 1e9 + 7;

  // calculates the number of ways a given set of numbers can form a BST
  unsigned long long solve(vector<int> &nums) {
    int n = nums.size();
    // recursion, when to return
    if (n <= 1)
      return 1;

    vector<int> l, r;
    // divide the nodes (other than root) into left & right based on BST
    for (int i = 1; i < n; i++) {
      if (nums[i] < nums[0])
        l.push_back(nums[i]);
      else
        r.push_back(nums[i]);
    }

    // divide and conquer
    int x = l.size(), y = r.size();
    // solve(l) * solve(r) represents the total number of BSTs
    // dp[x+y][x] plays the purmutation (choose the position of the x elements
    // in the left tree in the array, they still maintain the same order)
    return solve(l) * solve(r) % mod * dp[x + y][x] % mod;
  }

  int numOfWays(vector<int> &nums) {
    int n = nums.size();
    // resize the dp
    // i,j's range: 0 ~ n
    // this would init some cases such as dp[0][j]
    dp = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0));

    // fill in base cases
    for (int i = 1; i < n + 1; i++) {
      dp[i][0] = 1;
      dp[i][1] = i;
      dp[i][i - 1] = i;
      dp[i][i] = 1;
    }

    // fill the rest of the dp
    for (int i = 2; i < n + 1; i++) {
      for (int j = 2; j < n + 1; j++) {
        // core formula: dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
        // dp[i-1][j-1]: if i-th is not selected
        // dp[i-1][j]: if i-th is selected
        if (i >= j)
          dp[i][j] = (dp[i - 1][j] % mod + dp[i - 1][j - 1] % mod) % mod;
        else
          break;
      }
    }

    // -1 because we need to except the given case
    return solve(nums) - 1;
  }
};
