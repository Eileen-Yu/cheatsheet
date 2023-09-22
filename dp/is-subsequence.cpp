// https://leetcode.com/problems/is-subsequence/description
// 1. dp, tabulation
class Solution {
public:
  bool isSubsequence(string s, string t) {
    int m = s.length();
    int n = t.length();
    // dp[i] represents the number of matched chars in string s when we have
    // looped `i` chars in string t
    vector<int> dp(n + 1, -1);
    // base case
    dp[0] = 0;

    // tabulation
    for (int i = 1; i <= n; i++) {
      // # of matched chars till now = # of matched chars till the last char +
      // if this char matched
      dp[i] = dp[i - 1] + (t[i - 1] == s[dp[i - 1]]);
    }

    return dp[n] == m;
  }
};

// 2. most direct: 2 pointers
class Solution {
public:
  bool isSubsequence(string s, string t) {
    // idx to loop s
    int i = 0;

    // to loop t
    for (int j = 0; j < t.length(); j++) {
      // all chars in s have been checked
      if (i >= s.length())
        break;
      // else
      if (t[j] == s[i])
        i++;
    }

    // if all chars in s have been looped, return true
    return i == s.length();
  }
};
