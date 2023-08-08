// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// 1. find the pivot idx, then apply binary search 2 times, not exactly O(logn)
class Solution {
public:
  int binarySearch(int l, int r, int target, vector<int> &nums) {
    while (l <= r) {
      int mid = l + (r - l) / 2;
      int e = nums[mid];

      if (e == target)
        return mid;
      else if (e < target)
        l = mid + 1;
      else if (e > target)
        r = mid - 1;
    }

    return -1;
  }

  int search(vector<int> &nums, int target) {
    int n = nums.size();
    // pivot idx
    int k = n;
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] > nums[i + 1])
        k = i + 1;
    }

    // 1. apply binary search in the first range
    int l = 0, r = k - 1;
    int preRslt = binarySearch(l, r, target, nums);
    int nextRslt;

    // 1. if found the target
    if (preRslt != -1)
      return preRslt;

    // 2. if not found the target in the previous range
    // 2.1 the array is not rotated at all, means there is no the 2nd range
    if (k == n)
      return -1;

    // 2.2 if there is the 2nd range
    l = k, r = n - 1;
    nextRslt = binarySearch(l, r, target, nums);

    return nextRslt;
  }
};
