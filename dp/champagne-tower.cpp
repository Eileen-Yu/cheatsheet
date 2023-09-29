// https://leetcode.com/problems/champagne-tower/description
// tabulation: record the liquid actually flow to each glass
class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    // special case:
    if (poured == 0)
      return double(0);

    // dp[i][j] represents how much liquid is actually pourded into the j-th
    // glass in the i-th row dp[i][j] can > 1.0
    vector<vector<double>> dp(101, vector<double>(101, 0));
    // base case:
    dp[0][0] = double(poured);

    // loop each glass, to query for the glass in the i-th row, only needs to
    // loop to i-1th row because when we loop to each glass, we'll fill the dp
    // of the next level
    for (int i = 0; i < query_row; i++) {
      for (int j = 0; j < query_row; j++) {
        // the half of the liquid remains after pour into this current glass
        // namely how much liquid can flow to the next floor
        double excess = (dp[i][j] - 1.0) / 2.0;
        // if there are remains after fulling this glass
        // split the liquid equally into left & right glassed
        if (excess > 0) {
          dp[i + 1][j] += excess;
          dp[i + 1][j + 1] += excess;
        }
      }
    }

    // max return is 1.0 (a full glass), the actual recorded dp[i][j] can > 1.0
    return min(1.0, dp[query_row][query_glass]);
  }
};
