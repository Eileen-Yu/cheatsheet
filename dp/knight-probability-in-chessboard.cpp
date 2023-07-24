// https://leetcode.com/problems/knight-probability-in-chessboard/
// 1. plain recursion, would TLE in some cases due to duplicated calculation
class Solution {
public:
  // count the number of case that the chess can remain on the board
  double count = 0;
  // 8 possible directions
  vector<pair<int, int>> dir = {{1, -2}, {2, -1}, {2, 1},   {1, 2},
                                {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

  void recursion(int i, int j, int n, int k, int step) {
    // if out of boundary
    if (i < 0 || j < 0 || i >= n || j >= n)
      return;
    // if reach valid step number and still inside the board
    if (step == k) {
      count++;
      return;
    }

    for (auto d : dir) {
      recursion(i + d.first, j + d.second, n, k, step + 1);
    }
  }

  double knightProbability(int n, int k, int row, int column) {
    if (k == 0)
      return 1;

    recursion(row, column, n, k, 0);
    return count / pow(8, k);
  }
};

// 2. recursion + memoization to record the calculated result
class Solution {
public:
  // 8 possible directions
  vector<pair<int, int>> dir = {{1, -2}, {2, -1}, {2, 1},   {1, 2},
                                {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
  // dp[i][j][k] represents the probability of the knight remaining on the board
  // after k steps starting from (i,j)
  vector<vector<vector<double>>> dp;

  double recursion(int i, int j, int n, int k) {
    // memoization: if already calculated
    if (dp[i][j][k] != 0)
      return dp[i][j][k];

    // base case: if 0 steps remains to move, the knight 100% stay on the board
    if (k == 0)
      return 1.0;

    double prob = 0.0;
    // try each direction
    for (auto d : dir) {
      int x = i + d.first;
      int y = j + d.second;
      // if within the valid range
      if (x >= 0 && y >= 0 && x < n && y < n) {
        prob += recursion(x, y, n, k - 1) / 8.0;
      }
    }

    return dp[i][j][k] = prob;
  }

  double knightProbability(int n, int k, int row, int column) {
    // init the dp
    // i,j 's range: 0 ~ n-1
    // k's range: 1 ~ k, for convenience, use 0 ~ k
    dp = vector<vector<vector<double>>>(
        n, vector<vector<double>>(n, vector<double>(k + 1, 0.0)));
    return recursion(row, column, n, k);
  }
};
