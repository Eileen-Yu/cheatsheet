// https://leetcode.com/problems/knight-dialer
// convert the problem to: return the total number of "unique paths" the knight
// can travel making n hops
// key formula: dp[curDigit][n] += dp[prevDigit][n-1]
// use hash table to record each digit can be reached by which digits
class Solution {
public:
  int knightDialer(int n) {
    // base case:
    // only those already stands on the current digit can reach current digit
    if (n == 1)
      return 10;

    int mod = 1e9 + 7;

    // dp[possible digit][hop]
    // possible digit range: [0,9], so init to 10
    // hop range: [1,n], 0 is the base case, so init to n+1
    vector<vector<int>> dp(10, vector<int>(n + 1, 0));
    // fill in base case:
    // all dp[num][1] = 1, as when n = 1, there's only 1 case to reach each
    // digit: already stands on the digit
    for (int i = 0; i < 10; i++) {
      dp[i][1] = 1;
    }

    // hash table:
    // idx: current digit
    // value: digits that can reach the current digit
    vector<vector<int>> keypad = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
                                  {},     {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};

    // loop each hop possibility, start from n = 2
    for (int j = 2; j <= n; j++) {
      // loop each digit as current digit ([0,9])
      for (int i = 0; i < 10; i++) {
        // loop each possible previous digit
        for (int k = 0; k < keypad[i].size(); k++) {
          // key formula:
          // dp[curDigit][n] += dp[prevDigit][n-1]
          dp[i][j] = (dp[i][j] + dp[keypad[i][k]][j - 1]) % mod;
        }
      }
    }

    int ans = 0;
    // ans = sum up all dp[0-9][n]
    for (int i = 0; i < 10; i++) {
      ans = (ans + dp[i][n]) % mod;
    }

    return ans;
  }
};
