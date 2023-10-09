// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
// 1. binary search + expanding the range
// Time complexity: O(n) in worst case (e.g {1,1,1,1,....,1})
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> ans;
    int n = nums.size();
    int l = 0, r = n - 1;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        int start = mid, end = mid;

        // move left to find the starting idx
        while (start >= 0 && nums[start] == target)
          start--;
        ans.push_back(start + 1);

        // move right to find the ending idx
        while (end < n && nums[end] == target)
          end++;
        ans.push_back(end - 1);

        break;
      }

      else if (nums[mid] > target)
        r = mid - 1;
      else if (nums[mid] < target)
        l = mid + 1;
    }

    if (ans.empty())
      return {-1, -1};
    return ans;
  }
};
