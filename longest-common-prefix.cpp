// https://leetcode.com/problems/longest-common-prefix/description/
// 1. loop each string, update the ans each time
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string ans = strs[0];

    // loop each str in strs
    for (int i = 1; i < strs.size(); i++) {
      // loop each char in the potential ans
      for (int j = 0; j < ans.length(); j++) {
        if (ans[j] == strs[i][j])
          continue;

        // else update ans
        else
          ans = ans.substr(0, j);
      }
    }

    return ans;
  }
};
