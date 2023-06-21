// https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/
// sort + prefix sum to calculate parly sum up by prefixSum[large] -
// prefixSum[small]
class Solution {
public:
  long long minCost(vector<int> &nums, vector<int> &cost) {
    // pair: {nums[i], cost[i]}
    vector<pair<long, long>> p;
    int n = nums.size();
    // fill in the pair
    for (int i = 0; i < n; i++) {
      p.push_back({nums[i], cost[i]});
    }

    // sort the pair based on nums from small to large
    sort(p.begin(), p.end());
    // prefix sum for accumulate cost for 1 step movement
    // range: 0~n, init all to 0
    vector<long long> pre(n + 1, 0);
    // fill in the prefix sum
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + p[i].second;
    }

    long long ans = LLONG_MAX;
    // keep track of the costs on the left and right sides of the split
    long long left = 0, right = 0;
    // each time try to pick i-th element as the standard
    for (int i = 0; i < n; i++) {
      long long tmp = 0;

      // if pick the smallest as the standard
      if (i == 0) {
        left = 0;
        // calculate the right cost from the second to the last
        for (int j = 1; j < n; j++) {
          right +=
              (long long)(p[j].first - p[0].first) * (long long)p[j].second;
        }
        // update the ans if necessary
        tmp = left + right;
        ans = min(ans, tmp);
        continue;
      }

      // if spilt at somewhere in the middle
      // then steps of change on the right side needs to decrease,
      // while steps of change on the left side needs to increase

      // this calculates the distance between the current standard and previous
      // standard, namely how much each element need to change
      long long dist = p[i].first - p[i - 1].first;
      // the cost for this one and the latter ones that needs to increase to
      // reach the new standard
      right -= dist * (pre[pre.size() - 1] - pre[i]);

      // update the left side as elements need to increase to reach the new
      // standard there are totally i elements in the left pre[i] represents the
      // accumulate cost of the first i elements
      left += dist * pre[i];

      // update the ans if necessary
      tmp = left + right;
      ans = min(ans, tmp);
    }

    return ans;
  }
};
