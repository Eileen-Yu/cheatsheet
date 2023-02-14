// https://leetcode.com/problems/shortest-path-with-alternating-colors/description/
//
// BPF: the first time to reach a certain node means the minimum needed step
class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges,
                                       vector<vector<int>> &blueEdges) {
    // adjacency matrix:
    // the adj[i](node) = <neighbor, color>
    // example: [ [{0,1}, {1,1}], [{2,1}, {5,0}]...]
    vector<vector<pair<int, int>>> adj(n);
    // 0 represents for red
    for (auto i : redEdges) {
      adj[i[0]].push_back({i[1], 0});
    }
    // 1 represents for blue
    for (auto i : blueEdges) {
      adj[i[0]].push_back({i[1], 1});
    }

    // record the shortest path from node 0 to i-th node
    vector<int> ans(n, -1);
    ans[0] = 0;
    // because there is self-edges and parallel edges
    // visited[node][color], init to [[0,0], [0,0], ...]
    vector<vector<bool>> visited(n, vector<bool>(2, false));
    // queue: [node, color]
    queue<pair<int, int>> q;
    // put the first node into queue, neither red / blue, so use -1
    q.push({0, -1});
    int step = 0;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        auto [node, preColor] = q.front();
        q.pop();

        for (auto [neighbor, color] : adj[node]) {
          // has not been visited && color should not be the same
          if (!visited[neighbor][color] && color != preColor) {
            // mark this neighbor as visited
            visited[neighbor][color] = true;
            // if the neighbor has never been visited before
            // * the first time to reach the node means it takes the minimum
            // step = the shortest path
            if (ans[neighbor] == -1)
              ans[neighbor] = step + 1;
            q.push({neighbor, color});
          }
        }
      }
      step++;
    }
    return ans;
  }
};
