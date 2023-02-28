// https://leetcode.com/problems/edit-distance/description/
// 1. dp - bottom-up approach
class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    // Create a table to store the minimum edit distance between substrings of
    // word1 and word2
    int dp[m + 1][n + 1];

    // Initialize the table for the base cases
    for (int i = 0; i <= m; i++) {
      dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
      dp[0][j] = j;
    }

    // Compute the minimum edit distance for all substrings of word1 and word2
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          // Last characters match, no operation required
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          // Insert a character into word1
          int insertOp = dp[i][j - 1];
          // Delete a character from word1
          int deleteOp = dp[i - 1][j];
          // Replace a character in word1 with a character in word2
          int replaceOp = dp[i - 1][j - 1];
          // Take the minimum of the three operations and add 1
          dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
        }
      }
    }
    // Return the minimum edit distance between the entire strings
    return dp[m][n];
  }
};

// 2. dp + memorization, top-down approach
class Solution {
public:
  int recurse(string &word1, string &word2, int m, int n,
              vector<vector<int>> &dp) {
    // dp would record every operation
    // e.g when target at the last char of word1(m), how to operate every char
    // of word2(n) so if dp[m][n] != -1, means it already be calculated in this
    // way we can avoid duplicate calculation also, notice, in this method our
    // main target is to update dp
    if (dp[m][n] != -1)
      return dp[m][n];
    // if word1 is empty
    if (m == 0) {
      dp[m][n] = n;
      // no need followup calculation
      return n;
    }
    // if word2 is empty
    if (n == 0) {
      dp[m][n] = m;
      // no need followup calculation
      return m;
    }

    // if last character is the same, no more operation is needed
    if (word1[m - 1] == word2[n - 1])
      dp[m][n] = recurse(word1, word2, m - 1, n - 1, dp);

    // if last character is not same, then consider either insert/delete/replace
    else {
      // if insert
      int insertOpt = recurse(word1, word2, m, n - 1, dp);
      // if delete
      int deleteOpt = recurse(word1, word2, m - 1, n, dp);
      // if replace
      int replaceOpt = recurse(word1, word2, m - 1, n - 1, dp);
      // decide which to take
      dp[m][n] = 1 + min({insertOpt, deleteOpt, replaceOpt});
    }

    return dp[m][n];
  }

  int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    // init a 2-dimentional vector, ans set every element to -1
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    return recurse(word1, word2, m, n, dp);
  }

}

// 3. recurse, easy to understand, but would TLE in some cases
// time complexity: O(3^(m+n))
class Solution {
public:
  int recurse(string &word1, string &word2, int m, int n) {
    // if word1 is empty
    if (m == 0)
      return n;
    // if word2 is empty
    if (n == 0)
      return m;
    // if last character is the same
    if (word1[m - 1] == word2[n - 1])
      return recurse(word1, word2, m - 1, n - 1);

    // if last character is not same, then consider either insert/delete/replace
    else {
      // if insert
      int insertOpt = recurse(word1, word2, m, n - 1);
      // if delete
      int deleteOpt = recurse(word1, word2, m - 1, n);
      // if replace
      int replaceOpt = recurse(word1, word2, m - 1, n - 1);
      // decide which to take
      return 1 + min({insertOpt, deleteOpt, replaceOpt});
    }
  }

  int minDistance(string word1, string word2) {
    return recurse(word1, word2, word1.length(), word2.length());
  }
};
