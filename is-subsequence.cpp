// https://leetcode.com/problems/is-subsequence/description
// 1. most direct: 2 pointers
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

    if (i < s.length())
      return false;

    return true;
  }
};
