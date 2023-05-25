// https://leetcode.com/problems/new-21-game/description/
// dp: tabulation
// core idea: probability of getting to a certain node = sum (probability of
// getting to nodes 1 step away)

class Solution {
public:
  double new21Game(int n, int k, int maxPts) {
    // the max and min we may get is 0 and k-1+maxPts,
    // so these two cases are 100% <= n
    if (k == 0 || n >= k + maxPts)
      return (double)1.0;

    // dp[i] represents the probability of getting i points at some time
    // i's range: 0 ~ n
    vector<double> dp(n + 1, 0);
    // base case: the probability of getting 0 point is 100% as it's the start
    dp[0] = 1.0;

    // the probability if starting with 0 point
    double curSum = 1.0;
    double ans = 0.0;

    // fill in the tabulation
    for (int i = 1; i <= n; i++) {
      // the probability of getting i points
      dp[i] = curSum / maxPts;
      // add this one to the cumulative sum as we still need to reach to k
      // points
      if (i < k)
        curSum += dp[i];
      // keep track of probability between [k,n]
      else
        ans += dp[i];
      // for then next loop
      // e.g maxPts = 5, p6 = p5 + p4 + p3 + p2 + p1, these all need 1 step
      // but cannot include p0
      if (i - maxPts >= 0)
        curSum -= dp[i - maxPts];
    }

    return ans;
  }
};
