// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

class Solution {
public:
    long long getPiles(int num, vector<int>& candies){
      long long c = 0;
      for(auto q: candies)
        c += q / num;
      return c;  
    }  
  
    int maximumCandies(vector<int>& candies, long long k) {   
      long long i = 1; 
      long long j = 10000001;
      long long ans = 0;
      while(i <= j){
        long long mid = (i + j) / 2;
        long long piles = getPiles(mid, candies);
        
        if(piles >= k){
          ans = mid;
          i = mid + 1;
        }
        else{
          j = mid - 1;
        }
      }
      return ans;
    }
};
