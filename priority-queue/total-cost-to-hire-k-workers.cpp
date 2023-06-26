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

// 2. two pointers + 2 priority_queue(min heap)
class Solution {
public:
  long long totalCost(vector<int> &costs, int k, int candidates) {
    int n = costs.size();
    int i = 0, j = n - 1;
    // min heap, top is the smallest
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    long long ans = 0;

    while (k--) {
      // notice the boundary
      // only when j < i means we already put all elements into either pq1 or
      // pq2
      while (pq1.size() < candidates && i <= j)
        pq1.push(costs[i++]);
      while (pq2.size() < candidates && j >= i)
        pq2.push(costs[j--]);
      // in case one of the pq already become empty, then we can only pick from
      // another set it as INT_MAX to avoid error
      int min1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
      int min2 = pq2.size() > 0 ? pq2.top() : INT_MAX;
      if (min1 <= min2) {
        ans += min1;
        // already pick, remove this one from the costs
        pq1.pop();
      } else {
        ans += min2;
        // already pick, remove this one from the costs
        pq2.pop();
      }
    }

    return ans;
  }
};
