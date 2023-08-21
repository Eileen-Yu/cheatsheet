// https://leetcode.com/problems/repeated-substring-pattern/description/
// 2. plain version: try various patterns, make up a new string to compare with
// the original one
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    int n = s.length();

    // try various substrings
    for (int len = 1; len <= n / 2; len++) {
      // s must can be divided into multiple substrings
      if (n % len == 0) {
        string pattern = s.substr(0, len);

        // to make up a new string to compare with the original one
        string repeat = "";
        // i is the repeat number
        for (int i = 0; i < n / len; i++) {
          repeat += pattern;
        }

        if (repeat == s)
          return true;
      }
    }

    return false;
  }
};

// 3. plain version: try each substring to match
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
