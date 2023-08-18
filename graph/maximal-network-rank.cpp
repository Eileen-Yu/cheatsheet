// https://leetcode.com/problems/maximal-network-rank/description/
// adjacency matrix to record a node's neighbors
class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    // adjacency matrix
    vector<vector<int>> adj(n);
    for (auto i : roads) {
      int from = i[0];
      int to = i[1];
      // bidirection
      adj[from].push_back(to);
      adj[to].push_back(from);
    }

    int ans = INT_MIN;

    // loop each pair
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        int tmp = adj[i].size() + adj[j].size();

        // check if j is connected with i
        if (find(adj[i].begin(), adj[i].end(), j) != adj[i].end())
          tmp -= 1;

        // update the ans if necessary
        ans = max(ans, tmp);
      }
    }

    return ans;
  }
};
