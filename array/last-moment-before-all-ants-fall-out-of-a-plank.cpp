// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
// The ants change their way when they meet is equivalent to continue moving
// without changing their direction. So answer is the max distance for one ant
// to reach the end of the plank in the facing direction.
class Solution {
public:
  int getLastMoment(int n, vector<int> &left, vector<int> &right) {
    int ans = INT_MIN;

    // move to left, so 0 is the end
    for (auto i : left) {
      ans = max(ans, abs(i - 0));
    }

    // move to right, so n is the end
    for (auto i : right) {
      ans = max(ans, abs(i - n));
    }

    return ans;
  }
};
