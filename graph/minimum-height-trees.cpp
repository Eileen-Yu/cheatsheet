// https://leetcode.com/problems/minimum-height-trees/description/
// 1. BFS + indegree to eliminate leaf nodes level by level
// the root would be in the center between farthest leaf nodes
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    // special case
    if (n == 1)
      return {0};

    // adjacency matrix
    vector<vector<int>> adj(n);
    // idx: node, value: degree number
    vector<int> degree(n);
    // fill up the adj and degree
    for (auto i : edges) {
      int node1 = i[0];
      int node2 = i[1];
      adj[node1].push_back(node2);
      adj[node2].push_back(node1);
      degree[node1]++;
      degree[node2]++;
    }

    // BFS
    queue<int> q;
    // pick all the leaf nodes and add them to the queue
    for (int i = 0; i < degree.size(); i++) {
      if (degree[i] == 1)
        q.push(i);
    }

    vector<int> ans;

    while (!q.empty()) {
      int size = q.size();
      // empty the ans at each level
      ans.clear();

      while (size--) {
        int cur = q.front();
        // gradually remove leaf nodes level by level, and the root would be in
        // the center
        ans.push_back(cur);
        q.pop();

        for (auto neighbor : adj[cur]) {
          degree[neighbor]--;
          // if it becomes a new leaf node
          if (degree[neighbor] == 1) {
            q.push(neighbor);
          }
        }
      }
    }

    return ans;
  }
};

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
