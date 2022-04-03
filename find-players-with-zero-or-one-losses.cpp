//https://leetcode.com/problems/find-players-with-zero-or-one-losses/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
      int sz = matches.size();
      set<int>w;
      map<int,int>l;

      for(int i = 0;i < sz;i++){
        w.insert(matches[i][0]);
        l[matches[i][1]]++;
      }
      
      vector<int>ans2;
      set<int> :: iterator it;
      for(auto x: l){
        it = w.find(x.first);
        if(it != w.end()) w.erase(it);
        if(x.second == 1){
          ans2.push_back(x.first);
        }
      }
      
      vector<int>ans1(w.begin(),w.end());
        
      vector<vector<int>>ans;
      ans.push_back(ans1);
      ans.push_back(ans2);
      return ans;
    }
};
