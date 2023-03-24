// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
// go in & go out trick
// either DFS / BFS to traverse all nodes is ok
class Solution {
public:
  void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &visited,
           int &ans) {
    visited[node] = true;
    for (auto &[neighbor, dir] : adj[node]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        ans += dir;
        dfs(neighbor, adj, visited, ans);
      }
    }
  }

  int minReorder(int n, vector<vector<int>> &connections) {
    // {dst, dir}
    // if [A,B], A to B weight = 1, B to A weight = 0
    vector<vector<pair<int, int>>> adj(n);
    for (auto i : connections) {
      int start = i[0];
      int end = i[1];
      // only need to calculate those go out
      adj[start].push_back({end, 1});
      adj[end].push_back({start, 0});
    }

    vector<bool> visited(n, false);
    int ans = 0;

    dfs(0, adj, visited, ans);

    return ans;
  }
};
