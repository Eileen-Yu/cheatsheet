// https://leetcode.com/problems/unique-binary-search-trees/description/
// similar to
// https://leetcode.com/problems/unique-binary-search-trees-ii/descripsion
// 1. plain recursion + divide & conquer
class Solution {
public:
  int recursion(int start, int end) {
    // when to return: return 1 because there's only 1 possible tree(null /
    // single node)
    int size = end - start + 1;
    if (size == 0 || size == 1)
      return 1;

    // sum is the number of combinations when the range is [start, end]
    int sum = 0;
    // 1. divide: divide to left & right subtrees, the root is i
    for (int i = start; i <= end; i++) {
      int left = recursion(start, i - 1);
      int right = recursion(i + 1, end);
      // 2. conquer: left * right is the number of combinations when the root is
      // i
      sum += left * right;
    }

    return sum;
  }

  int numTrees(int n) { return recursion(1, n); }
};

// 2. memoization (recursion) + divide & conquer
class Solution {
public:
  // dp[i][j] represents the number of combinations when the range is [i,j]
  int dp[21][21];

  int recursion(int start, int end) {
    // when to return
    // 1. already calculated: memoization
    if (dp[start][end] != -1)
      return dp[start][end];

    // 2. only 1 possible combination (nullptr / single node)
    int size = end - start + 1;
    if (size == 0 || size == 1)
      return dp[start][end] = 1;

    // sum is the number of combinations when the range is [start, end]
    int sum = 0;
    // 1. divide: divide to left & right subtrees, the root is i
    for (int i = start; i <= end; i++) {
      int left = recursion(start, i - 1);
      int right = recursion(i + 1, end);
      // 2. conquer: left * right is the number of combinations when the root is
      // i
      sum += left * right;
    }

    return dp[start][end] = sum;
  }

  int numTrees(int n) {
    // init dp to -1
    memset(dp, -1, sizeof(dp));
    return recursion(1, n);
  }
};
