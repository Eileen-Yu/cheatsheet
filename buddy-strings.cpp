// https://leetcode.com/problems/buddy-strings/description/
// set tp check unique elements
class Solution {
public:
  bool buddyStrings(string s, string goal) {
    int n = s.length();
    // if the origin and the goal are the same
    if (s == goal) {
      // set to record the unique chars in the original string
      set<char> st(s.begin(), s.end());
      // if the # of unique chars in the original string is less than size of
      // the target it means we do some swap for duplicated elements so return
      // true
      return st.size() < goal.size();
    }
    // otherwise, it's obvious that we need to implement the swap
    int i = 0, j = n - 1;
    // find the first diff from the left
    while (i < n && s[i] == goal[i])
      i++;
    // find the first diff from the right
    while (j >= 0 && s[j] == goal[j])
      j--;
    // conduct the swap
    if (i < j)
      swap(s[i], s[j]);

    return s == goal;
  }
};
