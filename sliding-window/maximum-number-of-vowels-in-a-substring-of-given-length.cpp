// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
// substring of given length --> sliding window

class Solution {
public:
  // helper to check if this char is vowel or not
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  int maxVowels(string s, int k) {
    int i = 0, n = s.length();
    int tmp = 0, ans = 0;

    // move the right idx
    for (int j = 0; j < n; j++) {
      // count the frequency of vowel
      if (isVowel(s[j])) {
        tmp++;
      }

      // if the window size exceeds
      if (j - i + 1 > k) {
        // need to shorten the window
        // check if the cut one is vowel, if so, decrease
        if (isVowel(s[i]))
          tmp--;
        // shorten the window to keep the length = k
        i++;
      }
      // update the possible ans
      ans = max(ans, tmp);
    }

    return ans;
  }
};
