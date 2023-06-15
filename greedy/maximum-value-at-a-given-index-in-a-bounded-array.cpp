// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/
// greedy: init all to 1, then expand the range and try to increment each
// element in the range
class Solution {
public:
  int maxValue(int n, int index, int maxSum) {
    // at first we set each element to 1
    int ans = 1;
    // this is the remaining values that can be used
    maxSum -= n;
    int left = index, right = index;

    // don't need to cover the whole range, as we would do this later
    while (left > 0 || right < n - 1) {
      int len = right - left + 1;
      // try to add 1 to each element in this range
      if (len <= maxSum) {
        maxSum -= len;
        ans++;
        // expand the range, and control them not to be out of range
        left = max(0, left - 1);
        right = min(n - 1, right + 1);
      } else
        break; // if not enough values to assign to this range, break
    }

    // if there is remaining values, try to increase the peak
    ans += maxSum / n;
    return ans;
  }
};
