// https://leetcode.com/problems/repeated-substring-pattern/description/
// 1. plain version: try each substring to match
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    int n = s.length();

    // length of substring
    for (int len = 1; len <= n / 2; len++) {
      string pattern = s.substr(0, len);

      // check the rest of the string
      // 1. must can be fully devided into multiple substrings
      if ((n - len) % len != 0)
        continue;

      bool f = true;
      // 2. check if each substring is correct
      for (int i = len; i < n; i += len) {
        string sub = s.substr(i, len);
        // continue to check the next pattern
        if (sub != pattern) {
          f = false;
          break;
        }
      }

      if (f == true)
        return true;
    }

    return false;
  }
};
