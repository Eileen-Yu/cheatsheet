//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
//
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      vector<int> output;
      int i = 0;
      int j = numbers.size() -1;
      
      if(i == j) return output;
      
      while(i < j) {
        int rslt = numbers[i] + numbers[j];
        if(rslt > target){
          j -= 1;
        }
        if(rslt < target){
          i += 1;
        }
        else if(rslt== target){
          output.push_back(i+1);
          output.push_back(j+1);
          return output;
        }
      }
      return output;
    }  
};
