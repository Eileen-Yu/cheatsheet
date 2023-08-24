// https://leetcode.com/problems/sliding-window-maximum/
// 1. use pq to store {item, idx}, sort by item from largest to small
// each time when picking the max, check if it's within the window,
// if not, pop
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    // pq to sort {item, idx} from big to small
    priority_queue<pair<int, int>> pq;

    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
      // put the current {item, idx} into pq
      pq.push({nums[i], i});

      // only when we reach the window size, start to generate ans
      if (i >= k - 1) {
        // check if the maximum element in the pq is within the window size
        // if not, pop this maximum(won't use it again cuz it's already out of
        // range)
        while (i - pq.top().second >= k)
          pq.pop();

        // push the max in the window to ans
        ans.push_back(pq.top().first);
      }
    }

    return ans;
  }
};

// 2. plain version: apply the sliding window, use built-in max_element to find
// the maximum element in the subarray
// would TLE in some cases
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();

    vector<int> ans;

    // left side of the window
    int l = 0;
    // sliding the right side of the window
    for (int r = l + k - 1; r < n; r++) {
      // if exceeds the window, shorten it
      while (r - l + 1 > k)
        l++;

      // get the maximum element in this subarray
      int maxItem = *max_element(nums.begin() + l, nums.begin() + r + 1);
      ans.push_back(maxItem);
    }

    return ans;
  }
};
