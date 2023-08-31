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

// 2. sort first, then only need to compare first & last strings
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    // sort, so we only need to compare the first & last strings
    sort(strs.begin(), strs.end());
    int n = strs.size();
    string first = strs[0];
    string last = strs[n - 1];

    string ans = "";

    // loop each char
    for (int i = 0; i < min(first.length(), last.length()); i++) {
      // once the prefix are not the same
      if (first[i] != last[i]) {
        return ans;
      }

      // else, append this char to the ans
      ans += first[i];
    }

    return ans;
  }
};
