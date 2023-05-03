// https://leetcode.com/problems/longest-palindromic-substring/description/
// 1. dp
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

// 2. recursion + expand from center
class Solution {
public:
  string longestPalindrome(string s) {
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
      // pick the centric point, and try to expand to left and right
      // for odd string
      expand(i, i, s, ans);
      // for even string
      expand(i, i + 1, s, ans);
    }
    return ans;
  }

  void expand(int i, int j, string &s, string &ans) {
    while (i >= 0 && j < s.length()) {
      if (s[i] != s[j])
        break;
      // else expand to continue to check
      i--;
      j++;
    }

    // update the ans
    // left idx of current palindrome: i + 1
    // right idx of current palindrome: j - 1
    // current palindrome length: j-1 - (i+1) + 1 = j-i-1
    if (ans.length() < j - i - 1) {
      ans = s.substr(i + 1, j - i - 1);
    }
  }
};
