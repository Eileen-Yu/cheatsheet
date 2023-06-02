// https://leetcode.com/problems/detonate-the-maximum-bombs/description/
// DFS + matrix (but use idx of node with vector, instaead of map)

class Solution {
public:
  void dfs(vector<vector<int>> &adj, int &ans, vector<bool> &visited,
           int node) {
    // mark current as visited
    visited[node] = true;

    for (auto neighbor : adj[node]) {
      if (!visited[neighbor]) {
        ans++;
        dfs(adj, ans, visited, neighbor);
      }
    }

    return;
  }

  int maximumDetonation(vector<vector<int>> &bombs) {
    int n = bombs.size();
    if (n == 1)
      return 1;
    // adjacency matrix:
    // key: idx of current node
    // value: [idx of neighbor1, idx of neighbor 2...]
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    // fill in the adj matrix
    for (int i = 0; i < n; i++) {
      int x = bombs[i][0];
      int y = bombs[i][1];
      int r = bombs[i][2];

      for (int j = 0; j < n; j++) {
        if (j != i) {
          int a = bombs[j][0];
          int b = bombs[j][1];

          // if the bomb is within the range, mark it as a neighbor
          // Euclidean distance
          if (pow(a - x, 2) + pow(b - y, 2) <= pow(r, 2)) {
            adj[i].push_back(j);
          }
        }
      }
    }

    int ans = INT_MIN;
    // try to denote each bomb first
    for (int i = 0; i < n; i++) {
      // refresh the visited
      fill(visited.begin(), visited.end(), false);
      int tmp = 1;
      dfs(adj, tmp, visited, i);
      ans = max(ans, tmp);
    }

    return ans;
  }
};
