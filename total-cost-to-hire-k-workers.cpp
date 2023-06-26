// https://leetcode.com/problems/total-cost-to-hire-k-workers/
// 1. plain version, would TLE in some cases
// due to min_element() and v.erase() all need to loop the whole arr
class Solution {
public:
  long long ans = 0;

  // find the min element in the range
  auto helper(int start, int end, vector<int> &costs) {
    auto minIt = min_element(start + costs.begin(), end + costs.begin() + 1);
    return minIt;
  }

  long long totalCost(vector<int> &costs, int k, int c) {
    while (k--) {
      int len = costs.size();
      // init the iterator
      auto minIt = costs.begin();

      if (len < 2 * c) {
        minIt = helper(0, len - 1, costs);
        ans += *minIt;
        costs.erase(minIt);
      } else {
        auto minIt1 = helper(0, c - 1, costs);
        auto minIt2 = helper(len - c, len - 1, costs);
        int minNum;
        if (*minIt1 <= *minIt2) {
          minNum = *minIt1;
          minIt = minIt1;
        } else {
          minNum = *minIt2;
          minIt = minIt2;
        }
        ans += minNum;
        costs.erase(minIt);
      }
    }

    return ans;
  }
};
