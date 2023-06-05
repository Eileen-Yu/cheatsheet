// https://leetcode.com/problems/number-of-provinces/description/
// --> find how many clusters are there in the graph
// 1. DFS
class Solution {
public:
  void dfs(int node, vector<vector<int>> &adj, vector<int> &visited) {
    visited[node] = true;
    for (auto neighbor : adj[node]) {
      if (!visited[neighbor]) {
        dfs(neighbor, adj, visited);
      }
    }

    return;
  }

  int findCircleNum(vector<vector<int>> &isConnected) {
    int ans = 0;
    int n = isConnected.size();

    // adjacency matrix, 0 ~ n
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        // change node idx to 0,1...,n-1
        if (isConnected[i][j] == 1)
          adj[i].push_back(j);
      }
    }

    vector<int> visited(n, false);

    // try to start at each node
    for (int i = 0; i < n; i++) {
      if (visited[i])
        continue;
      // else, it is a new cluster
      ans++;
      dfs(i, adj, visited);
    }

    return ans;
  }
};
