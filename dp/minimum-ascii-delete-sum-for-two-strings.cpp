// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// very similar to
// https://leetcode.com/problems/longest-common-subsequence/description/

// 1. recursion: TLE
// use the recursion to get the maximum ASCII sum of the common substring
// then minimum-ascii-delete-sum = total - maximum-sum-of-the-common-string
class Solution {
public:
  // return the max ASCII sum of the common chars in the two strings
  // m, n is the length of the substring
  int recursion(int m, int n, string s1, string s2) {
    // base case: when to return
    if (m == 0 || n == 0)
      return 0;

    // if there are commmon chars
    // adds twice the ASCII value of that character to the result
    // then use the recursion to deal with the rest chars
    if (s1[m - 1] == s2[n - 1])
      return 2 * int(s1[m - 1]) + recursion(m - 1, n - 1, s1, s2);

    // else if the chars are not equal in 2 strings,
    // either try to delete the current char from s1 / s2
    return max(recursion(m - 1, n, s1, s2), recursion(m, n - 1, s1, s2));
  }

  int minimumDeleteSum(string s1, string s2) {
    // record the sum of ASCII in s1 and s2
    int sum = 0;
    for (auto i : s1)
      sum += int(i);
    for (auto j : s2)
      sum += int(j);

    int m = s1.length(), n = s2.length();

    return sum - recursion(m, n, s1, s2);
  }
};

// 2. memoization: MLE
// It's still recursion, just use a dp to record some calculated results to
// avoid some duplications
class Solution {
public:
  // return the max ASCII sum of the common chars in the two strings
  // m, n is the length of the substring
  int recursion(int m, int n, string s1, string s2, vector<vector<int>> &dp) {
    // memoization: if already filled up
    if (dp[m][n] != -1)
      return dp[m][n];

    // base case: when to return
    if (m == 0 || n == 0)
      return dp[m][n] = 0;

    // if there are commmon chars
    // adds twice the ASCII value of that character to the result
    // then use the recursion to deal with the rest chars
    if (s1[m - 1] == s2[n - 1])
      return dp[m][n] =
                 2 * int(s1[m - 1]) + recursion(m - 1, n - 1, s1, s2, dp);

    // else if the chars are not equal in 2 strings,
    // either try to delete the current char from s1 / s2
    return dp[m][n] = max(recursion(m - 1, n, s1, s2, dp),
                          recursion(m, n - 1, s1, s2, dp));
  }

  int minimumDeleteSum(string s1, string s2) {
    // record the sum of ASCII in s1 and s2
    int sum = 0;
    for (auto i : s1)
      sum += int(i);
    for (auto j : s2)
      sum += int(j);

    int m = s1.length(), n = s2.length();
    // dp[m][n] represents the max ASCII sum of the common chars between
    // substring1(size = m) and substring2 (size = n) init all to -1
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    return sum - recursion(m, n, s1, s2, dp);
  }
};

// 3. tabulation
// use loops to fill in the table from small substrings to large substrings
// solve the problem based on sub-problems
// (use tabulation to replace the recursion)
class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    // record the sum of ASCII in s1 and s2
    int sum = 0;
    for (auto i : s1)
      sum += int(i);
    for (auto j : s2)
      sum += int(j);

    int m = s1.length(), n = s2.length();
    // dp[m][n] represents the max ASCII sum of the common chars between
    // substring1(size = m) and substring2 (size = n) init all to -1
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // fill in the table
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        // if the 2 chars are the same
        // sum ASCII = these 2 + accumulation before
        // else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        dp[i][j] = s1[i - 1] == s2[j - 1]
                       ? 2 * int(s1[i - 1]) + dp[i - 1][j - 1]
                       : max(dp[i][j - 1], dp[i - 1][j]);

        // if (s1[i-1] == s2[j-1]) dp[i][j] = 2*int(s1[i-1]) + dp[i-1][j-1];
        // if the 2 chars are different
      }
    }

    return sum - dp[m][n];
  }
};
