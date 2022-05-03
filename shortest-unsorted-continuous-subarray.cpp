// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
//
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      vector<int> n = nums; 
      sort(n.begin(), n.end()); // the sorted one
      int s = 0, e = nums.size() - 1;        
      
      // the starting one
      while (s < nums.size() && n[s] == nums[s]) s++;
      // the end one
      while (e > s && n[e] == nums[e]) e--;  // e > s, so no need to specially deal with 0

      return e - s + 1;                           
    }
};
