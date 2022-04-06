// https://leetcode.com/problems/3sum-with-multiplicity/
//

// O(n^2)
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
      unordered_map<int,int>mp;
      int sz = arr.size(), ans = 0;
      int mod = 1e9 + 7;
      
      for(int i = 0; i < sz; i++){
        ans = (ans + mp[target - arr[i]]) % mod ; // all pairs before arr[i]
        
        for(int j = 0; j < i; j++){
          mp[arr[i]+arr[j]]++;
        }
      }
      
      return ans;
    }
};
