// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
// binary search
// each time record `mid` for easier range adjustment
// (just need to exclude mid)
class Solution {
public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int l = 0, r = arr.size() - 1;
    // record the max element and its index
    int m = INT_MIN, idx = -1;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      // we already record `mid` each time
      // so next round don't need to involve the `mid`
      if (arr[mid] > m) {
        m = arr[mid];
        idx = mid;
      }

      // compared with mid+1 to avoid mid - 1 < 0
      if (arr[mid] < arr[mid + 1])
        l = mid + 1;
      else if (arr[mid] > arr[mid + 1])
        r = mid - 1;
    }

    return idx;
  }
};
