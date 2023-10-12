// https://leetcode.com/problems/next-permutation/description/
// classic algorithm to find the next permutation:
// step 1: find the breaking point (nums[i] < nums[i+1]) from right to left
// step 2: find the first element that > breaking point on the right side of the
// breaking point from right to left, swap it with the breaking point
// step 3: reverse the right part of the breaking point

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    // 1. find the breaking point, namely the first element that nums[i] <
    // nums[i+1] from right to left
    int idx = -1;
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        idx = i;
        break;
      }
    }

    // 2. find the first element on the right of idx that > nums[i], from right
    // to left if the original nums is already reversed, like {3,2,1}, then idx
    // = -1, will skip this step
    for (int i = n - 1; i > idx && idx != -1; i--) {
      if (nums[i] > nums[idx]) {
        swap(nums[i], nums[idx]);
        break;
      }
    }

    // 3. reverse the nums on the right of idx
    // if the original nums is already reversed, like {3,2,1}, this step would
    // directly reverse it to {1,2,3}
    reverse(nums.begin() + idx + 1, nums.end());
  }
};
