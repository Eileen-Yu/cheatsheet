// https://leetcode.com/problems/path-with-minimum-effort/
//
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
      vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}}; // 4 directions
      int m = heights.size();
      int n = heights[0].size();
      pq.push({0,0,0}); //starting node (effort, row,col)
      int ans = 0;
      
      while(!pq.empty()) {
        vector<int> p = pq.top();
        pq.pop();
        int i = p[1];
        int j = p[2];
        
        if(heights[i][j] == -1) continue; // this node already traversed
        
        ans = max(ans,p[0]);
        if(i == m-1 && j == n-1) return ans; // this node is the last one
        
        for(int k = 0; k < 4; k++) {
          int ni = i + dir[k][0];
          int nj = j + dir[k][1];
          
          if(ni < 0 || nj < 0 || ni >= m || nj >= n || heights[ni][nj] == -1) continue;  // not invalid node
          
          pq.push({abs(heights[ni][nj]-heights[i][j]), ni, nj});
        }
        
        heights[i][j] = -1; // mark as traversed
      }
      
      return ans;    
    }
};
