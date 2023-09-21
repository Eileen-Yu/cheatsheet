// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// use the merge method to merge these 2 sorted arrays
// same concept in the merge sort
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    // idx to loop nums1 and nums2
    int i = 0, j = 0;
    vector<int> merged;

    // similar to merge sort to merge the 2 arrs
    while (i < m && j < n) {
      if (nums1[i] <= nums2[j]) {
        merged.push_back(nums1[i]);
        i++;
      }

      else if (nums1[i] > nums2[j]) {
        merged.push_back(nums2[j]);
        j++;
      }
    }

    // append the remains in nums1 / nums2
    while (i < m) {
      merged.push_back(nums1[i]);
      i++;
    }

    while (j < n) {
      merged.push_back(nums2[j]);
      j++;
    }

    // find t[<72;40;7Mhe mid of the merged arr
    int mid = (m + n) / 2;
    // 1. if odd elements, only 1 mid
    if ((m + n) % 2 == 1) {
      return double(merged[mid]);
    }
    // else if even elements, ans = (mid1 + mid2) / 2
    return double(merged[mid - 1] + merged[mid]) / 2;
  }
};
