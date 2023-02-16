// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/

// DFS
class Solution {
public:
  long long dfs(int node, int &seats, long long &ans, vector<int> &visited,
                vector<vector<int>> &adj) {
    // count of nodes that passed, namely count of people
    // this node should add 1 to count
    long long count = 1;
    // mark as visited
    visited[node] = true;

    for (auto neighbor : adj[node]) {
      if (!visited[neighbor])
        count += dfs(neighbor, seats, ans, visited, adj);
    }
    // has travsed one complete path

    // e.g, if there're 3 people and 5 seats:
    // 1. no full car, ans = 0
    long long tmp = count / seats;
    // 2. need one not full car, ans = 1
    if (count % seats)
      tmp++;
    // if this is not the root
    if (node != 0)
      ans += tmp;

    return count;
  }

  long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
    // number of nodes
    int n = roads.size() + 1;
    // adjacency matrix
    vector<vector<int>> adj(n);
    // since it's bidirectional
    for (auto i : roads) {
      adj[i[0]].push_back(i[1]);
      adj[i[1]].push_back(i[0]);
    }

    long long ans = 0;
    vector<int> visited(n, false);
    dfs(0, seats, ans, visited, adj);

    return ans;
  }
};
