// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
//
// Because no matter how we travse,
// there must be a path from start(1) to end(n)
// so we can either choose BFS / DFS
// both approaches would visit all nodes connected with the start
//
// 1. BFS
class Solution {
public:
  int minScore(int n, vector<vector<int>> &roads) {
    // adjacency matrix
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>({}));
    for (auto i : roads) {
      int start = i[0];
      int end = i[1];
      int dis = i[2];
      adj[start].push_back({end, dis});
      adj[end].push_back({start, dis});
    }
    // BFS
    queue<int> q;
    // start from node 1
    q.push(1);
    // record if the node has been visited to avoid loop
    // because no matter how we traverse,
    // we still can reach the destination
    set<int> visited;
    // mark the first node as visited
    visited.insert(1);

    int ans = INT_MAX;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int tmp = q.front();
        q.pop();

        for (auto [dst, dis] : adj[tmp]) {
          ans = min(ans, dis);
          if (visited.find(dst) == visited.end()) {
            q.push(dst);
            visited.insert(dst);
          }
        }
      }
    }

    return ans;
  }
}

// 2. BFS plain verision, would TLE
class Solution {
public:
  int minScore(int n, vector<vector<int>> &roads) {
    // adjacency matrix
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>({}));
    for (auto i : roads) {
      int start = i[0];
      int end = i[1];
      int dis = i[2];
      adj[start].push_back({end, dis});
      adj[end].push_back({start, dis});
    }
    // BFS
    queue<int> q;
    // start from node 1
    q.push(1);
    // record directional path that has been visited to avoid loop
    set<pair<int, int>> visited;
    int ans = INT_MAX;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int tmp = q.front();
        q.pop();

        for (auto [dst, dis] : adj[tmp]) {
          if (visited.find({tmp, dst}) == visited.end()) {
            q.push(dst);
            visited.insert({tmp, dst});
            ans = min(ans, dis);
          }
        }
      }
    }

    return ans;
  }
};

// 3. DFS
class Solution {
public:
  void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &visited,
           int &ans) {
    visited[node] = true;

    for (auto [dst, dis] : adj[node]) {
      ans = min(ans, dis);
      if (!visited[dst]) {
        dfs(dst, adj, visited, ans);
      }
    }
  }

  int minScore(int n, vector<vector<int>> &roads) {
    // adjacency matrix
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>({}));
    for (auto i : roads) {
      int start = i[0];
      int end = i[1];
      int dis = i[2];
      adj[start].push_back({end, dis});
      adj[end].push_back({start, dis});
    }

    vector<int> visited(n + 1, false);

    int ans = INT_MAX;
    dfs(1, adj, visited, ans);

    return ans;
  }
};
