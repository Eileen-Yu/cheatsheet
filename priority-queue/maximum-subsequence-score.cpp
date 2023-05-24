// https://leetcode.com/problems/maximum-subsequence-score/description/
// PQ: first we sort nums2 from big to small,
// this ensure each time when we loop we are always at the minimum one
// then we keep a PQ of k-1 size,
// this ensure each time we must have nums1[idx] in our sum, while idx is the
// index of current nums2(namely the min)
class Solution {
public:
  long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    // pair: elements in nums2, idx
    vector<pair<int, int>> v;

    for (int i = 0; i < nums2.size(); i++) {
      v.push_back({nums2[i], i});
    }

    // sort v from big to small elements
    sort(v.rbegin(), v.rend());

    // pq to maintain the k-1th largest elements in nums1
    priority_queue<int, vector<int>, greater<int>> pq;

    long long sum = 0;
    long long ans = INT_MIN;

    // loop each nums2 from big to small as the min to be multiplied
    for (auto i : v) {
      auto [nums2, idx] = i;
      // since we loop the v from big to small elements in nums2,
      // we can make sure each time the min element is current one
      int min = nums2;
      // as we always keep the num of included elements as k-1, each time we can
      // try to add current one
      sum += nums1[idx];
      pq.push(nums1[idx]);

      // try to update the ans
      if (pq.size() == k)
        ans = max(ans, min * sum);

      // keep the pq.size == k-1 for the next loop
      if (pq.size() > k - 1) {
        // cut of the smallest one
        sum -= pq.top();
        pq.pop();
      }
    }

    return ans;
  }
}
