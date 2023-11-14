i // https://leetcode.com/problems/unique-length-3-palindromic-subsequences
  // track the first & last occurance of each letter
  // then count the unique elements in between these 2 occurance
  // use hash table to record the first & last idx of each letter
    class Solution {
public:
  int countPalindromicSubsequence(string s) {
    // hash table:
    // idx range: [0,25] to represent the 26 letters
    // value: the idx of each letter's first position in the string
    vector<int> firstIdx(26, INT_MAX);
    // record the idx of each letter's final position in the string
    vector<int> lastIdx(26, -1);

    // fill in the firstIdx & lastIdx
    for (int i = 0; i < s.length(); i++) {
      // record the first position of the letter
      firstIdx[s[i] - 'a'] = min(firstIdx[s[i] - 'a'], i);
      // record the final position of the letter
      lastIdx[s[i] - 'a'] = i;
    }

    int ans = 0;
    // loop the 26 letters
    for (int i = 0; i < 26; i++) {
      // only if the letter appeared twice
      if (firstIdx[i] < lastIdx[i]) {
        // count of unique palindrome = number of the unique elements between
        // the first & last identical letters range: [firstIdx[i] + 1,
        // lastIdx[i])
        ans += unordered_set<char>(begin(s) + firstIdx[i] + 1,
                                   begin(s) + lastIdx[i])
                   .size();
      }
    }

    return ans;
  }
};
