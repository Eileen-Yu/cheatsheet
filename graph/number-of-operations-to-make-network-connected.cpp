// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
// 1. DFS
class Solution {
public:
  void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;

    for (auto i : adj[node]) {
      if (!visited[i]) {
        dfs(i, adj, visited);
      }
    }
  }

  int makeConnected(int n, vector<vector<int>> &connections) {
    // to connect n nodes, at least need n-1 cables
    int cables = connections.size();
    if (cables < n - 1)
      return -1;

    vector<vector<int>> adj(n);
    for (auto i : connections) {
      int com1 = i[0];
      int com2 = i[1];
      adj[com1].push_back(com2);
      adj[com2].push_back(com1);
    }

    vector<bool> visited(n, false);

    // record the number of clusters
    // one cluster contains several connected nodes
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i, adj, visited);
        count++;
      }
    }

    return count - 1;
  }
};

// 2. BFS
class Solution {
public:
  void bfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        int tmp = q.front();
        q.pop();

        for (auto i : adj[tmp]) {
          if (!visited[i]) {
            q.push(i);
            visited[i] = true;
          }
        }
      }
    }
  }

  int makeConnected(int n, vector<vector<int>> &connections) {
    // to connect n nodes, at least need n-1 cables
    int cables = connections.size();
    if (cables < n - 1)
      return -1;

    vector<vector<int>> adj(n);
    for (auto i : connections) {
      int com1 = i[0];
      int com2 = i[1];
      adj[com1].push_back(com2);
      adj[com2].push_back(com1);
    }

    vector<bool> visited(n, false);

    // record the number of clusters
    // one cluster contains several connected nodes
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        bfs(i, adj, visited);
        count++;
      }
    }

    return count - 1;
  }
};
