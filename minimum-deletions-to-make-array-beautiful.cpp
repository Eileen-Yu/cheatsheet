// https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/


class Solution {
public:
    int minDeletion(vector<int>& nums) {
      int i = 0;
      int ans = 0;
      for(int i = 0; i < nums.size() - 1; i++){
        nums[i] == nums[i+1] ? ans++: i++;            // if they are equal, increment the ans
                                                      // else just skip
      }
      
      if ( (nums.size() - ans) % 2 != 0 ) ans++;      // size of vector - ans = the final vector size after deletions
      
      return ans;
    }
};
