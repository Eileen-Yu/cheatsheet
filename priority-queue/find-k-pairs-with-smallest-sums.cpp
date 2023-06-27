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

// 2. improvement:
// as nums1, nums2 are sorted, we can split the case if pq.size() > k, pop():
// (1) the current sum is pop(), then we can break because the latter nums2[j]
// would only become larger;
// (2) the current sum is stored and the previous pair
// is pop(), then need to try the latter nums2[j]

// We can avoid loop some unnecessary pairs in this way
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

        // core idea: maintain the pq size as k

        // 1. if pq.size < k, we need to put this into the pq anyway
        if (pq.size() < k) {
          pq.push({sum, {u, v}});
          continue;
        }

        // 2. else if pq.size already == k
        // 2.1 if this sum is smaller than the largest sum in the pq
        // then we pick this one
        if (sum < pq.top().first) {
          pq.pop();
          pq.push({sum, {u, v}});
        }
        // 2.2 if this sum is bigger than the largest sum in the pq
        // we break the inner loop as nums2 would only increase, don't need to
        // try the latter ones
        else if (sum > pq.top().first)
          break;
      }
    }

    vector<vector<int>> ans;
    while (!pq.empty()) {
      // front is the bigger one, theoratically we need to insert the smaller to
      // the begin but this problem don't need, so just push back
      ans.push_back({pq.top().second});
      pq.pop();
    }

    return ans;
  }
};
