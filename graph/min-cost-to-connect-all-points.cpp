// https://leetcode.com/problems/min-cost-to-connect-all-points/

// 1. Prim's algorithm to find the Minimum Spanning Tree(min cost to connect all
// nodes) priority_queue  O(n^2logn) + cache to store the min cost to each node
// + if visited(connected) or not
class Solution {
public:
  // calculate the manhattan distance between 2 nodes
  int getDist(vector<int> p1, vector<int> p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
  }

  int minCostConnectPoints(vector<vector<int>> &points) {
    // number of nodes
    int n = points.size();

    // {cost to reach the node, node}, sort by cost from small to big
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    // init with the start node, the cost to reach the start node is 0
    pq.push({0, 0});

    // cache to store the minimum cost to each node
    // idx: node, value: min cost
    vector<int> minCost(n, INT_MAX);

    // record if a node has already been connected
    vector<bool> visited(n, false);

    int ans = 0;

    // Prim's algorithm: find a minimum spanning tree (MST) for a weighted,
    // undirected graph Starting from an arbitrary vertex, selects the edge with
    // the smallest weight at each step and adds it to the MST
    while (!pq.empty()) {
      // get the next with the smallest cost
      auto [cost, node] = pq.top();
      pq.pop();

      // if the node already been connected
      if (visited[node])
        continue;

      // else, connect this node
      visited[node] = true;
      ans += cost;

      // calculate the dist between this node and the other unconnected nodes
      for (int i = 0; i < n; i++) {
        if (!visited[i]) {
          int dist = getDist(points[node], points[i]);
          // if the dist to this unconnected node is smaller than the cached
          // dist,
          if (dist < minCost[i]) {
            // 1. update the minCost
            minCost[i] = dist;
            // 2. push it to pq
            pq.push({dist, i});
          }
        }
      }
    }

    return ans;
  }
};
