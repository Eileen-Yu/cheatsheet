// https://leetcode.com/problems/min-cost-to-connect-all-points/


// priority_queue  O(n^2logn)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      //pair<distance,ith node>
      priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int>>> pq;
      int n = points.size();
      vector<int> visited(n,false);
      pq.push({0,0});
      int ans = 0;
      
      
      for(int i = 1; i < n; i++){
        pair<int,int> temp = pq.top();
        //pq.pop();
        visited[temp.second] = true;
        
        for(int i = 0; i < n; i++){
          pq.push({abs(points[temp.second][0]-points[i][0]) + abs(points[temp.second][1]-points[i][1]),i});
        }
        
        while(visited[pq.top().second]){
          pq.pop();
        }
        ans += pq.top().first;
      }
      
      return ans;
    }
};






// simplest version of Prim that finds the mininal element by a loop
class Solution {
public:
    int manhattan(int x, int y, int xi, int yi){
      return abs(x-xi)+abs(y-yi);
    }
    
  
    int minCostConnectPoints(vector<vector<int>>& points) {
      int n = points.size();
      vector<int> visited(n,false);
      vector<int> cost(n,INT_MAX);
      int ans = 0;
      
      auto updateCost = [&](int x, int y){    // for func in func
        for(int i = 0; i < n; i++){  
          if (visited[i] == true) continue; // prevent loop
          int xi = points[i][0];
          int yi = points[i][1];
          cost[i] = min(cost[i],manhattan(x,y,xi,yi));
        }
      };
      
      //start from point 0
      visited[0] = true;
      cost[0] = 0;
      updateCost(points[0][0],points[0][1]);
     
      // Prim's 
      for(int i = 1; i < n; i++){   // n-1 edges
        int j = -1; // not start yet
        
        for(int k = 0; k < n; k++){ 
          if(visited[k] == true) continue;
          if(j == -1 || cost[j] > cost[k])
            j = k; // j is the nearest
        }
        
        ans += cost[j];
        visited[j] = true; // won't traverse again
        updateCost(points[j][0],points[j][1]);   // j is the next starting
      }
       
      return ans;
    }
};
