// https://leetcode.com/problems/is-graph-bipartite/
// DFS
//
class Solution {
public:
  vector<int> col;
  vector<int> visit; // if visited

  bool dfs(int v, int c, vector<vector<int>> &g) {
    col[v] = c;
    visit[v] = 1;
    for (auto child : g[v]) {
      // if not traversed, check child
      if (visit[child] == 0) {
        // flip colour for child
        if (dfs(child, c ^ 1, g) == false)
          return false;
      } else if (col[v] == col[child])
        return false;
    }
    return true;
  }

  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();
    col.resize(n);
    visit.resize(n);

    for (int i = 0; i < n; i++) {
      // for every not visited node, check
      if (visit[i] == 0 && dfs(i, 0, graph) == false)
        return false;
    }
    return true;
  }
};
