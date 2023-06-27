// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// top k --> priority queue
// 1. plain version, would TLE in some cases
// because there is O(n^2) for looping each pair
class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    // pq: {sum, {u,v}}, the top is the biggest sum
    priority_queue<pair<int, vector<int>>> pq;

    // try each pair and put them into the queue
    int n = nums1.size(), m = nums2.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int u = nums1[i], v = nums2[j];
        int sum = u + v;
        pq.push({sum, {u, v}});
        // pop the biggest one, to maintain the size of the pq as k
        if (pq.size() > k)
          pq.pop();
      }
    }

    vector<vector<int>> ans;
    while (!pq.empty()) {
      // front is the bigger one, so insert the smaller to the begin
      ans.insert(ans.begin(), pq.top().second);
      pq.pop();
    }

    return ans;
  }
};
