// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
// 1. sort + modify the original arr
class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
    // sort the nums from small to big
    sort(arr.begin(), arr.end());

    // check if the first one is 1
    if (arr[0] > 1)
      arr[0] = 1;

    for (int i = 1; i < arr.size(); i++) {
      if (arr[i] - arr[i - 1] <= 1)
        continue;

      // else, already confirm arr[i] - arr[i-1] > 1, can decrease it
      // make it + 1 to be as big as possible while meet the requirement
      arr[i] = arr[i - 1] + 1;
    }

    // the last one is the max one
    return arr.back();
  }
};
