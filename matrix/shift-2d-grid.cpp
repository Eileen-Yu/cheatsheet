// https://leetcode.com/problems/shift-2d-grid/
// special math skills, extra space
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>> ans(m,vector<int>(n));
      
      for(int i = 0; i < m;i++){
        for(int j = 0; j < n; j++){
          int newj = (j + k) % n;
          int newi = (i + (j+k) / n) % m;
          ans[newi][newj] = grid[i][j];
        }
      }
      
      return ans;
    }
};

// in-place loop
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
      int m = grid.size();
      int n =grid[0].size();
      int a = 0;
      
      while(k>0) {
        int b = grid[m-1][n-1];        // last element, 9
        for(int i  = 0; i < m; i++){
          if(i%2 == 0 ){
            a = grid[i][n-1];
          }
          else if(i%2 == 1){ 
            b = grid[i][n-1];
          }
          
          for(int j = n-1; j >0 ; j--){
            grid[i][j] = grid[i][j-1];
          }
          if(i%2 == 0) {grid[i][0] = b;}
          if(i%2 == 1) {grid[i][0] = a;}
        }
      
        k--;
      }
      return grid;
    }
};
