// https://leetcode.com/problems/search-insert-position/
//

// O(logn)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int i = 0, j = nums.size() - 1;
      int ans = -1;
      
      while(i <= j) {
        int mid = (i+j) / 2;
        
        if(nums[mid] == target) 
          return mid;
        
        if(nums[mid] < target)
          i = mid + 1;
        else j = mid - 1;
      }
      
      return i;    
    }
};




//O(n)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int ans = -1;
      for(int i = 0; i < nums.size();i++) {
        if(nums[i] == target)
          return i;
        if(nums[i] > target)
          return i;
      }
      if(ans == -1) ans = nums.size();
      return ans;
    }
};
