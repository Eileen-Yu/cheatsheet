// https://leetcode.com/problems/length-of-the-longest-valid-substring/
// sliding window (3 pointers):
// 1. move left side from back to end
// 2. right side it the restriction condition, cannot be reached
// 3. there's a third pointer in between the left & right side to check if it's
// the forbidden word if is, needs to update right side
class Solution {
public:
  int longestValidSubstring(string word, vector<string> &forbidden) {
    // use set to store the forbidden words for easier search
    unordered_set<string> st;
    // the maximum length of the forbidden word
    int maxLen = 0;
    // fill in the set and maxLen
    for (auto i : forbidden) {
      st.insert(i);
      maxLen = max(maxLen, (int)i.length());
    }

    int n = word.length();
    // record the right side of the window, cannot be included in the possible
    // ans
    int right = n;
    int ans = 0;

    // slide the left side of the window
    // loop from back to start
    for (int i = n - 1; i >= 0; i--) {
      string tmp = "";

      // start from the current char, try to extend to maximize the length of
      // the possible ans till right end
      for (int j = i; j < right && j - i < maxLen; j++) {
        // append the char to tmp string
        tmp.push_back(word[j]);

        // check if it's a forbidden string
        if (st.count(tmp)) {
          // the current char cannot be included in the possible ans
          // update right side, as this cannot be included
          right = j;
          // directly break
          break;
        }
      }

      // update ans if necessary
      // since right is unreachble, it's right - 1 - i + 1 = right - i
      ans = max(ans, right - i);
    }

    return ans;
  }
};
