// https://leetcode.com/problems/repeated-substring-pattern/description/
// 1. clever way to check if a string is composed by repeated substrings:
// if a string s can be constructed by repeating a substring, then concatenating
// two copies of s together and removing the first and last character would
// still contain s as a substring.
// (this would check the body + head)
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    // concatenate 2 original s to make up a new string
    string newStr = s + s;

    // remove the first & last char of the new string
    string toFind = newStr.substr(1, newStr.length() - 2);

    // if we still can find the original string in the updated toFind, return
    // true
    return toFind.find(s) != string::npos;
  }
};

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
