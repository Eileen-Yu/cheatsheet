// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/
// sliding window:
// try T / F separately, so abstract it as a function `sliding`
class Solution {
public:
  // return the maximum size of a window containing k different elements from
  // `positive`
  int sliding(string answerKey, int k, char positive) {
    int n = answerKey.length();
    int l = 0;
    // record the number of diffenrent one (T/F) within the window
    int c = 0;
    int ans = INT_MIN;
    // try to extend the window
    for (int r = 0; r < n; r++) {
      if (answerKey[r] != positive)
        c++;
      // shorten the window
      while (c > k) {
        if (answerKey[l] != positive)
          c--;
        l++;
      }

      ans = max(ans, r - l + 1);
    }

    return ans;
  }

  int maxConsecutiveAnswers(string answerKey, int k) {
    return max(sliding(answerKey, k, 'T'), sliding(answerKey, k, 'F'));
  }
};
