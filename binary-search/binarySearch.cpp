// https://leetcode.com/problems/binary-search/:while
// plain binary search
// core idea: search the ans between [l, r]
// time complexity: Ologn
class Solution {
public:
    int search(vector<int>& nums, int target) {
      int l = 0, r = nums.size() - 1;
      
      while (l <= r) {
        int mid = l + (r-l) / 2;
        
        if (nums[mid] == target) return mid;
        // as mid has been checked as not the ans, so the range can be narrowed to mid - 1
        else if (nums[mid] > target) r = mid - 1;
        // same as above
        else l = mid + 1;
      }

      return -1;

    }
};
