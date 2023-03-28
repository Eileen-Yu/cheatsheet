// https://leetcode.com/problems/minimum-cost-for-tickets/description/
// DP: for each day, pick the minimum cumulative cost

class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    // record the cumulative price till day[i]
    vector<int> dp(366, INT_MAX);
    dp[0] = 0;
    // to loop the days in daylist
    int j = 0;

    // loop for days from 1 - 365
    for (int i = 1; i < 366; i++) {
      if (i == days[j] && j < days.size()) {
        // 1. if buy 1-day ticket
        dp[i] = min(dp[i], dp[i - 1] + costs[0]);

        // 2. if buy 7-day ticket
        if (i >= 7)
          dp[i] = min(dp[i], dp[i - 7] + costs[1]);
        // in case days = [1,4,6] costs = [3, 4, 10]
        else
          dp[i] = min(dp[i], costs[1]);

        // 3. if buy 30-day ticket
        if (i >= 30)
          dp[i] = min(dp[i], dp[i - 30] + costs[2]);
        else
          dp[i] = min(dp[i], costs[2]);

        j++;
      }

      // no traveling cost on this day
      else
        dp[i] = dp[i - 1];
    }

    return dp[365];
  }
};
