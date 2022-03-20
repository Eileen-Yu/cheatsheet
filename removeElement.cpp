//https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int j = 0;
      int count = 0;
      for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != val) {
          nums[j] =nums[i];
          j += 1; 
          count += 1;
        }
      }
      return count;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      if(nums.size() == 0) return 0;
      
      int count = 0; 
      int i = 0;
      int j = nums.size() - 1;
      
      if(i==j) {
        if(nums[i] == val) return 0;
        else return 1;
      }
      while(i != j) {
        if(nums[i] == val) {
          count += 1;
          std::swap(nums[i],nums[j]);
          j -=1;
        }
        else i +=1;
      }
      if(nums[i] == val) count += 1;
      
      return nums.size() - count;
    }
};
