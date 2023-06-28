// https://leetcode.com/problems/path-with-maximum-probability/
// 1. plain version, DFS, would TLE in some cases
class Solution {
public:
  void dfs(int node, int end, double tmp, double &ans,
           vector<vector<pair<int, double>>> adj, vector<bool> visited) {
    // if reach the end node
    if (node == end) {
      ans = max(ans, tmp);
      return;
    }
    // else, try to continue with each neighbor of the current node
    for (auto i : adj[node]) {
      int neighbor = i.first;
      double p = i.second;
      if (!visited[neighbor]) {
        // mark as visited
        visited[neighbor] = true;
        dfs(neighbor, end, tmp * p, ans, adj, visited);
        // unmark the current neighbor to try another path
        visited[neighbor] = false;
      }
    }
  }

  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start, int end) {
    // adjacency matrix:
    // idx: start, value: [neighbor, probability]
    vector<vector<pair<int, double>>> adj(n);
    // fill in the adj
    for (int i = 0; i < edges.size(); i++) {
      int start = edges[i][0];
      int end = edges[i][1];
      double p = succProb[i];
      // undirected graph
      adj[start].push_back({end, p});
      adj[end].push_back({start, p});
    }

    vector<bool> visited(n, false);
    visited[start] = true;
    double tmp = 1.0, ans = 0.0;

    for (auto i : adj[start]) {
      int neighbor = i.first;
      double tmp = i.second;
      dfs(neighbor, end, tmp, ans, adj, visited);
    }

    return ans;
  }
};

// 2. BFS + priority queue,
// always pick the node with the highest probability to reach as the starting
// point and only push to the pq when a higher probability appears (only in this
// case the neighbor's probability may increase)
// and use a vector<double> to track the  maxProbability to reach the i-th node
// this would also help to avoid loop, as a loop would only make the probability
// smaller
class Solution {
public:
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start, int end) {
    // adjacency matrix:
    // idx: start, value: [neighbor, probability]
    vector<vector<pair<int, double>>> adj(n);
    // fill in the adj
    for (int i = 0; i < edges.size(); i++) {
      int start = edges[i][0];
      int end = edges[i][1];
      double p = succProb[i];
      // undirected graph
      adj[start].push_back({end, p});
      adj[end].push_back({start, p});
    }

    // {probability need till this node, node}, the max probability is on the
    // top
    priority_queue<pair<double, int>> pq;
    pq.push({1.0, start});

    // record the highest probability to reach the i-th node
    vector<double> prob(n, 0.0);

    while (!pq.empty()) {
      double probTillNow = pq.top().first;
      int cur = pq.top().second;
      pq.pop();

      for (auto i : adj[cur]) {
        int neighbor = i.first;
        double probToNeighbor = i.second;
        double newP = probTillNow * probToNeighbor;

        // this would avoid a loop in nature:
        // only a different node may make the prob larger
        if (newP > prob[neighbor]) {
          prob[neighbor] = newP;
          pq.push({newP, neighbor});
        }
      }
    }

    return prob[end];
  }
};
