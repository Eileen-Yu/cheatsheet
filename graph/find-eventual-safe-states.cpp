// https://leetcode.com/problems/find-eventual-safe-states/description/
// = detect if there is a cycle in the graph
// all the nodes not in the cycle are the ans
// 1. DFS: color algorithm
class Solution {
public:
  void dfs(vector<vector<int>> &graph, int cur, vector<int> &visited) {
    // mark this one as being visited
    visited[cur] = 2;

    // check each path
    for (auto neighbor : graph[cur]) {
      // check along one path
      if (visited[neighbor] == 0)
        dfs(graph, neighbor, visited);
      // if visited[neighbor] hasn't been updated to 1, means there is a cycle
      // once there is a cycle in this path, then this node cannot be an ans,
      // directly return
      if (visited[neighbor] == 2)
        return;
    }

    // if all nodes along this path have been checked and not involved in a
    // cycle, then it can be an ans
    visited[cur] = 1;
  }

  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    // color algorithm:
    // 0 means never visited
    // 1 means visited but not in a cycle
    // 2 means visited and is part of a cycle
    vector<int> visited(n, 0);

    // check all nodes one by one
    for (int i = 0; i < n; i++) {
      // if this node hasn't been visited/checked
      if (visited[i] == 0)
        dfs(graph, i, visited);
    }

    // all those nodes mark as '1' are the ans
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (visited[i] == 1)
        ans.push_back(i);
    }

    return ans;
  }
};
