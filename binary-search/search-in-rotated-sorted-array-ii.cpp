// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
// still maintain the partially sorted feature
// so drop the duplications first to decide which half is sorted in order to go
// into
class Solution {
public:
  bool search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
      // skip the duplications to ensure there's at least a half can be in order
      // otherwise for special case [1,0,1,1,1] target = 0, l = mid = r = 1
      // it would be hard to decide which half is sorted to go into
      // l < r to avoid l+1 / r-1 out of boundary
      while (l < r && nums[l] == nums[l + 1])
        l++;
      while (l < r && nums[r] == nums[r - 1])
        r--;

      int mid = l + (r - l) / 2;

      // if we found the target
      if (nums[mid] == target)
        return true;

      // if the first half is in order
      if (nums[l] <= nums[mid]) {
        if (nums[l] <= target && target < nums[mid])
          r = mid - 1;
        else
          l = mid + 1;
      } else { // if the second half is in order
        if (nums[mid] < target && target <= nums[r])
          l = mid + 1;
        else
          r = mid - 1;
      }
    }

    return false;
  }
};
