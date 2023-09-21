// https://leetcode.com/problems/merge-strings-alternately/description/
// 2 pointers, string
// concept is used in merge sort

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    string ans = "";
    int i = 0, j = 0;
    int m = word1.length(), n = word2.length();

    while (i < m && j < n) {
      ans += word1[i];
      i++;
      ans += word2[j];
      j++;
    }

    while (i < m) {
      ans += word1[i];
      i++;
    }

    while (j < n) {
      ans += word2[j];
      j++;
    }

    return ans;
  }
};
