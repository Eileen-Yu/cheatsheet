// https://leetcode.com/problems/binary-search/:while

class Solution {
public:
    int search(vector<int>& nums, int target) {
      
      if(nums.size() == 0 ) return -1;
     
      int l = 0;
      int r = nums.size() - 1;
      
      while(l<r){
        int middle = (l+r) / 2;
        if(target == nums[middle]){ return middle;}
        if( target< nums[middle]) {
          r =  middle - 1;
        }
        if(target > nums[middle]) {
          l = middle + 1;
        }
      }
     
      if( l == r) {
        if(nums[l] == target) return l;
      }
      
      return -1;
    }
};
