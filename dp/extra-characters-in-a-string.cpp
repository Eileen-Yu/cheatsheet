// https://leetcode.com/problems/extra-characters-in-a-string/
// tabulation: try to split the original s at various length
class Solution {
public:
  int minExtraChar(string s, vector<string> &dictionary) {
    int n = s.length();
    // dp[i] represents the minExtraChar when the substring len = i(s[:i])
    vector<int> dp(n + 1, INT_MAX);
    // base case
    dp[0] = 0;

    // for easier search if a word is in the dict
    unordered_map<string, int> mp;
    for (auto word : dictionary) {
      mp[word]++;
    }

    // try to split the original s for each length
    for (int i = 1; i <= n; i++) {
      // init with the worst case: this char is an extra char
      dp[i] = dp[i - 1] + 1;

      // try to see if we can find a matched word with this char in the dict
      // so loop the various length of the substring
      for (int l = 1; l <= i; l++) {
        // calculate the starting idx base on the length and the ending idx(i-1)
        // fomular: i-1-j+1 = l, j = i-l
        string subStr = s.substr(i - l, l);
        // if the substring is in the dict, need to update dp[i] if necessary
        if (mp.find(subStr) != mp.end())
          dp[i] = min(dp[i], dp[i - l]);
      }
    }

    return dp[n];
  }
};
