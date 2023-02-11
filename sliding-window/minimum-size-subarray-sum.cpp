// https://leetcode.com/problems/minimum-size-subarray-sum
//
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int i = 0;
      int j = 0;
      int sum = 0;
      int rslt = nums.size() + 1;
        
      while(j < nums.size()) {
        sum += nums[j];
        
        if(sum < target) {
          j += 1;
        }
        
        else {
          while (sum >= target) {
            rslt = min(rslt, j - i + 1);
            sum = sum - nums[i];
            i += 1;
          }
          j += 1;
        }
      }
    if(rslt == nums.size() + 1) return 0;
    else return rslt;
    }
};


// ugly one
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int rslt = nums.size() + 1;
      int i = 0;                          
      int j = 0;
      int sum = 0;
      
      while( i<=j && j <= nums.size() -1 ) {
        if(i == j) { 
          if(nums[i] >= target) {
            return 1;
          }
          if (i == 0 && j == 0){
            sum += nums[j];
            j += 1;
            if( j < nums.size()) {sum += nums[j];}
            continue;
          }
          else {
            sum = nums[i];
            j += 1;
            if (j <= nums.size() - 1) {sum += nums[j];}
          }
        }
        
        if(sum >= target) {
          if(j-i+1 < rslt) {rslt = j - i + 1;}
          sum -= nums[i];
          i += 1;
        }
        else {
          if (j == nums.size() -1) {
            break;
          }
          else if (j < nums.size() - 1){
            j += 1;
            sum += nums[j];
          }
        }
        
      }
      
      if(rslt <= nums.size()) return rslt;
      else return 0;
    }
};

