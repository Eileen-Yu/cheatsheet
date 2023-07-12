// https://leetcode.com/problems/find-eventual-safe-states/description/
// = detect if there is a cycle in the graph
// all the nodes not in the cycle are the ans
// 1. DFS: color algorithm
class Solution {
public:
  // check if a node is part of a cycle
  bool isCycle(vector<vector<int>> &graph, vector<int> &visited, int cur) {
    // if we meet the node again, it's a cycle
    if (visited[cur] == 1)
      return true;

    // if we never visit it
    if (visited[cur] == 0) {
      visited[cur] = 1;
      // we check for its neighbors
      for (auto neighbor : graph[cur]) {
        if (isCycle(graph, visited, neighbor))
          return true;
      }
    }

    // if there is no cycle, update the mark to 2
    visited[cur] = 2;
    return false;
  }

  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    // color algorithm:
    // 0 = never visited
    // 1 = visited and in a cycle
    // 2 = visited and not part of a cycle
    vector<int> visited(n, 0);
    vector<int> ans;

    // check each node one by one
    for (int i = 0; i < n; i++) {
      if (!isCycle(graph, visited, i))
        ans.push_back(i);
    }

    return ans;
  }
};
