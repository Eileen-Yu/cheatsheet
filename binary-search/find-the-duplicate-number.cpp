// https://leetcode.com/problems/find-the-duplicate-number/description/
// the goal is to find duplication in range [1, n], instead of find in the input
// so even if the input is not sorted, we can still implement the binary search

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    // randomly try a num from range [1, n] (as pivot)
    // and based on the description, nums.size = n + 1;
    int l = 1, r = nums.size() - 1;
    int ans = 0;

    while (l <= r) {
      // pivot
      int mid = l + (r - l) / 2;

      // record # of nums that <= pivot
      int c = 0;
      for (auto i : nums) {
        if (i <= mid)
          c++;
      }

      // there should be exactly `pivot` nums in range [1, pivot] if there's no
      // duplication if c > pivot, there must be duplications in range [1,
      // pivot]
      if (c > mid) {
        ans = mid;
        r = mid - 1;
      }

      else if (c <= mid)
        l = mid + 1;
    }

    return ans;
  }
};
