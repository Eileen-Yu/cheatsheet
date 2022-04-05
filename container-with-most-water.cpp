// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
      int j = height.size() - 1;
      int i = 0;
      int ans = 0;
      int hi = 0, hj = 0;
      int h = 0, area = 0;
      while(i<j){
        hi = height[i];
        hj = height[j];
        h = min(hi,hj);
        area = h * (j-i);
        ans = max(ans,area);
        
        if(height[i] < height[j])
          i++;
        else j--;
        
      }
      
      return ans;
    }
};
