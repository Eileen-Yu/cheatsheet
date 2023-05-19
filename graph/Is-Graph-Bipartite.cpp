// https://leetcode.com/problems/is-graph-bipartite/
// 1. DFS(recursion) + color algorithm to check if neighbors are in the same set
// if yes, return false
//
class Solution {
public:
  bool dfs(vector<vector<int>> &adj, vector<int> &visited, int node) {
    // current node's set
    int set = visited[node];
    // another set
    int op;
    if (set == 1)
      op = 2;
    else if (set == 2)
      op = 1;

    // the neighbor of this node should be in another set
    for (auto neighbor : adj[node]) {
      // if the neighbor already visited, and in the same set as this node
      if (visited[neighbor] != 0 && visited[neighbor] == visited[node])
        return false;
      // not visited yet, mark it as in the other set, continue to check for its
      // neighbors
      else if (visited[neighbor] == 0) {
        visited[neighbor] = op;
        // once there is false, we ruturn,
        // otherwise we continue to check
        if (dfs(adj, visited, neighbor) == false)
          return false;
      }
    }

    return true;
  }

  bool isBipartite(vector<vector<int>> &graph) {
    // number of nodes
    int n = graph.size();
    // color algorithm:
    // 0: not visited
    // 1: visited, mark as set1
    // 2: visited, mark as set2
    // init all nodes as not visited
    vector<int> visited(n, 0);

    // check each node as the starter
    for (int i = 0; i < n; i++) {
      // because the graph is not connected, so it may be another sets of
      // connected nodes
      if (visited[i] == 0) {
        visited[i] = 1;
        if (dfs(graph, visited, i) == false)
          return false;
      }
    }

    return true;
  }
};
