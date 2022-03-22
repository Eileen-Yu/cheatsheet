// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/

class Solution {
public:
    int countHillValley(vector<int>& nums) {
      if(nums.size() <= 2) return 0;
      
      vector<int> vect;
      vect.push_back(nums[0]);
      int j = 0, count = 0;
      
      for (int i = 1; i < nums.size(); i++ ) {
        if(nums[i] != vect[j]) {
          vect.push_back(nums[i]);
          j++;
        }
        
      }
      
      for(int j = 1; j < vect.size() - 1; j++) {
        if( (vect[j-1] > vect[j] && vect[j+1] > vect[j]) || 
           (vect[j-1] < vect[j] && vect[j+1] < vect[j]) ) count++;
      }
      
     return count;
    
    }
};
