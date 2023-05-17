// https://leetcode.com/problems/minimum-height-trees/description/
// 1. BFS + indegree to eliminate nodes

// 2. BFS, would TLE in some cases
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    // adjacency matrix
    vector<vector<int>> adj(n);
    for (auto i : edges) {
      int node1 = i[0];
      int node2 = i[1];
      adj[node1].push_back(node2);
      adj[node2].push_back(node1);
    }

    vector<bool> visited(n, false);
    // BFS
    queue<int> q;
    // idx: level number, value[node1, node2...]
    map<int, vector<int>> record;

    // try pick each node as the root
    for (int i = 0; i < n; i++) {
      // empty the queue
      q = queue<int>();
      // reset the visited flag
      fill(visited.begin(), visited.end(), false);
      // reset the level number
      int tmp = 0, minLevel = INT_MAX;
      q.push(i);

      while (!q.empty()) {
        int size = q.size();
        tmp++; // a new level
        // the height already exceed the recorded minimum
        if (tmp > minLevel)
          break;

        while (size--) {
          int cur = q.front();
          // mark as visited
          visited[cur] = true;
          q.pop();

          for (auto neighbor : adj[cur]) {
            if (!visited[neighbor]) {
              q.push(neighbor);
            }
          }
        }
      }

      minLevel = min(tmp, minLevel);
      record[tmp].push_back(i);
    }

    return record.begin()->second;
  }
};
