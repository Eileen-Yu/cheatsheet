// https://leetcode.com/problems/scramble-string/description/
// dp: bottom to top

class Solution {
public:
  bool isScramble(string s1, string s2) {
    int n = s2.length();
    // if s1.len != s2.len
    if (n != s1.length()) {
      return false;
    }
    // 3D hash tableL dp[n+1][n][n], initialize to false
    // dp[l][i][j] reflect whether a substring of length l starting at index i
    // of s1 and a substring of length l starting at index j of s2 can be
    // scrambled into each other p.s because length is 1~n, and it's hash table,
    // so n+1
    bool dp[n + 1][n][n];
    memset(dp, false, sizeof(dp));

    // initialize the dp, from l = 1
    // concept: bottom to top
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s1[i] == s2[j])
          dp[1][i][j] = true;
      }
    }

    // pick any length from 2-n
    for (int l = 2; l <= n; l++) {
      for (int i = 0; i <= n - l; i++) {
        for (int j = 0; j <= n - l; j++) {
          // Divide the strings into two substrings at all possible positions
          for (int k = 1; k < l; k++) {
            if (dp[k][i][j] &&
                    dp[l - k][i + k]
                      [j + k] || // Check if the two substrings are scrambled
                                 // strings of each other in same order
                dp[k][i][l - k + j] &&
                    dp[l - k][i + k][j]) { // in swapped order
              dp[l][i][j] = true;
              break; // would only break the internal loop
            }
          }
        }
      }
    }

    return dp[n][0][0];
  }
}
