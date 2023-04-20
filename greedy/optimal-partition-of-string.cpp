// https://leetcode.com/problems/optimal-partition-of-string/description/

// greedy (try to extend as much as possible each time)
// + hash table (to count frequency of each char)
class Solution {
public:
    int partitionString(string s) {
      // hash table to count number of char
      vector<int> table(26,0);
      int ans = 1;
  
      for(auto i : s) {
        int idx = i - 'a';
        if (table[idx] != 0) {
          ans++;
          // reset the hash table
          fill(table.begin(), table.end(), 0);
          table[idx]++;
        } else {
          table[idx]++; 
        }
      }

      return ans;
       
    }
};
