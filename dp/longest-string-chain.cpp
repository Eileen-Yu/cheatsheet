// https://leetcode.com/problems/longest-string-chain/description/
// tabulation:
// dp[i] represents the longest chain length to reach current word i
// tmp is the substring by dropping any char from the word i
// key transition formular: dp[i] = max(dp[i], dp[tmp] + 1)
class Solution {
public:
  int longestStrChain(vector<string> &words) {
    // sort the array by increasing word length
    sort(words.begin(), words.end(),
         [](string &a, string &b) { return a.length() < b.length(); });

    // dp represents {string, longest chain length to reach this string}
    unordered_map<string, int> dp;
    int ans = 1;
    // loop each word
    for (auto i : words) {
      // base case: each single word is a word chain whose length = 1
      dp[i] = 1;

      // try to drop 1 char from the word to see if it's in the chain
      // j : the idx of the dropped char
      for (int j = 0; j < i.length(); j++) {
        // string after dropped the certain char
        string tmp = i.substr(0, j) + i.substr(j + 1);
        // if tmp is the predecessor of j
        if (dp.find(tmp) != dp.end()) {
          // pick the longest chain to reach this word
          dp[i] = max(dp[i], dp[tmp] + 1);
          // update the ans if necessary
          ans = max(ans, dp[i]);
        }
      }
    }

    return ans;
  }
};
