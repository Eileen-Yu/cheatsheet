// https://leetcode.com/problems/k-radius-subarray-averages/
// 1. use sliding window because there is a fixed window size in this
// problem(2k+1)
class Solution {
public:
  vector<int> getAverages(vector<int> &nums, int k) {
    int n = nums.size();
    // init the ans
    vector<int> ans(n, -1);
    // special case
    if (n < k)
      return ans;

    // window size
    int size = 2 * k + 1;
    long long windowSum = 0;

    for (int i = 0; i < n; i++) {
      // 1. add up all elements
      windowSum += nums[i];
      // 2. adjust the window size
      // the range exceeds the window, needs to shorten it by cut 1 element
      if (i >= size)
        windowSum -= nums[i - size];

      // 3. check if the window is complete, and fill in the ans
      // if the window has reached the desired size
      if (i >= size - 1)
        ans[i - k] = windowSum / size;
    }

    return ans;
  }
};
// 2. prefixSum to solve the partly accmulation problem
class Solution {
public:
  vector<int> getAverages(vector<int> &nums, int k) {
    int n = nums.size();
    // init the ans
    vector<int> ans(n, -1);
    // window size
    int s = 2 * k + 1;

    // prefixSum[i+1] = accumulate[0...i]
    vector<long long> prefixSum(n + 1, 0);
    // fill in the prefixSum
    for (int i = 0; i < n; i++) {
      prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    // get partial accumulation by prefixSum[big] - prefixSum[small]
    for (int i = k; i + k < n; i++) {
      ans[i] = (prefixSum[i + k + 1] - prefixSum[i - k]) / s;
    }

    return ans;
  }
};
// 3. plain version (would TLE for some cases)
class Solution {
public:
  vector<int> getAverages(vector<int> &nums, int k) {
    int n = nums.size();
    // init the ans
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
      int l = i - k, r = i + k;
      if (l < 0 || r >= n)
        continue;

      // else
      // accumulate(iterator1, iterator2, start) pick [l, r), so +1
      ans[i] =
          accumulate(nums.begin() + l, nums.begin() + r + 1, 0) / (r - l + 1);
    }

    return ans;
  }
};
