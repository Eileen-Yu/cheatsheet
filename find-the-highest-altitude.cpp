// https://leetcode.com/problems/find-the-highest-altitude/description/
// prefix sum
class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int ans = 0;
    int tmp = 0;
    for (auto i : gain) {
      tmp += i;
      ans = max(ans, tmp);
    }

    return ans;
  }
};
