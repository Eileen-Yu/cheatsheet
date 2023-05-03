// https://leetcode.com/problems/longest-palindromic-substring/description/
// dp
class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    // special case
    if (n == 0)
      return "";

    // initialize a dp to record if string between idx i and j is a palindrome
    bool dp[n][n];
    // init all to false
    memset(dp, false, sizeof(dp));

    // base case: single element is also a palindrome
    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
    }

    // init the ans to s[0], for special case such as s = "a" / s = "ac"
    string ans = "";
    ans += s[0];
    // loop from the end to fill in the dp gradually
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j]) {
          // if this substring between idx i and j is a palindrome
          // only 2 chars is also a palindrome
          if (dp[i + 1][j - 1] || j - i == 1) {
            // mark it as a palindrome
            dp[i][j] = true;

            // check if we need to update the ans with s.substr[i,j]
            if (ans.length() < j - i + 1) {
              ans = s.substr(i, j - i + 1);
            }
          }
        }
      }
    }

    return ans;
  }
};
