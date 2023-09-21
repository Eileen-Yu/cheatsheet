// https://leetcode.com/problems/median-of-two-sorted-arrays
// use binary search to find the correct position to divide nums1 to put x
// elements from nums1 to the first half
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();

    // always try to divide the smaller array
    if (m > n)
      return findMedianSortedArrays(nums2, nums1);

    // binary search to try to take x elements from nums1
    int l = 0, r = m;
    // + 1 to cover both odd & even cases
    int total = m + n + 1;

    while (l <= r) {
      // there are `first` elements from nums1 that make up the first half of
      // the final merged array
      int first = l + (r - l) / 2;
      // there are `second` elements from nums2 that make up the first half of
      // the final merged array
      int second = total / 2 - first;

      // the last element from nums1 that make up the first half
      int l1 = INT_MIN;
      // the last element from nums2 that make up the first half
      int l2 = INT_MIN;
      // the first element from nums1 that make up the second half
      int r1 = INT_MAX;
      // the first element from nums2 that make up the second half
      int r2 = INT_MAX;

      if (first > 0)
        l1 = nums1[first - 1];
      if (second > 0)
        l2 = nums2[second - 1];
      if (first < m)
        r1 = nums1[first];
      if (second < n)
        r2 = nums2[second];

      // if we divide at the correct position
      if (l1 <= r2 && l2 <= r1) {
        // if there are even elements
        if ((n + m) % 2 == 0)
          return (max(l1, l2) + min(r1, r2)) / 2.0;
        // e[<72;21;6Mlse if there are odd elements
        else
          return max(l1, l2);
      }

      // if we not divide at the correct position, need to continue the binary
      // search if last element from nums1 is too big, need to pick fewer
      // elements from nums1
      else if (l1 > r2)
        r = first - 1;
      // else, need to pick more elements from nums1
      else
        l = first + 1;
    }

    return 0;
  }
};
