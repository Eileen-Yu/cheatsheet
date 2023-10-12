// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// 1. 2 pointers
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    // idx in the nums to be replaced with unique elements
    // start from the second element, because the first is certain to be in the
    // new nums
    int i = 1;

    // loop each element in the nums, also start from the second one
    for (int j = 1; j < nums.size(); j++) {
      // if this is a new unique element
      if (nums[j] != nums[i - 1]) {
        nums[i] = nums[j];
        // move to the next idx
        i++;
      }
    }

    return i;
  }
};

// 2. use std::unique to remove duplications in a sorted array
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
  }
};
