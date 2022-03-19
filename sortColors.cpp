// https://leetcode.com/problems/sort-colors/


class Solution {
public:
    void sortColors(vector<int>& nums) {
      int i = -1;
      int j = nums.size();
      int k = 0;
      while(k != j) {
        if(nums[k] == 1) {k += 1;}
       
        else if(nums[k] < 1) {
          i += 1;
          std::swap(nums[i], nums[k]);
          k += 1;
        }
        
        else if(nums[k] > 1) {
          j -= 1;
          std::swap(nums[k], nums[j]);
        }
      }
    }
};
