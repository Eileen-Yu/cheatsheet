// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
// 1. direct wayL priority_queue, which is based on heap
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> pq;
    for (auto i : nums) {
      pq.push(i);
    }

    int tmp;
    while (k--) {
      tmp = pq.top();
      pq.pop();
    }

    return tmp;
  }
};
