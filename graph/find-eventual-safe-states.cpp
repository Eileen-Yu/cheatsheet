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

// 2. BFS: indegree
class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    // idx: to, value: [from1, from2...]
    vector<vector<int>> indegree(n);
    // idx: node, value: number of nodes this node can lead to
    vector<int> degree(n, 0);

    // fill up the indegree
    for (int i = 0; i < n; i++) {
      for (auto j : graph[i]) {
        int from = i, to = j;
        indegree[to].push_back(from);
        degree[from]++;
      }
    }

    // for BFS
    queue<int> q;
    // put those terminal nodes as the start ones in the BFS
    for (int i = 0; i < n; i++) {
      if (degree[i] == 0) {
        q.push(i);
      }
    }

    vector<int> ans;
    // BFS
    while (!q.empty()) {
      // from
      int cur = q.front();
      q.pop();
      // all nodes that the indegree can be eliminated are ans
      ans.push_back(cur);

      // check all the nodes that can lead to this node
      for (auto neighbor : indegree[cur]) {
        degree[neighbor]--;
        // if all the outdegree can be eliminated, then it's not in the cycle
        if (degree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }

    sort(ans.begin(), ans.end());
    return ans;
  }
};
