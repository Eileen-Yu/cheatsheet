// https://leetcode.com/problems/min-cost-to-connect-all-points/

// 1. Prim's algorithm to find the Minimum Spanning Tree
// (min cost to connect all nodes)

// step:
// 1. push start node into pq
// 2. select the unvisited node with the min cost from pq
// 3. if it's not visited:
//    3.1 mark it as visited, and add the cost to ans
//    3.2 calculate the cost between this node and other unvisited nodes
//    3.3 update the cache(record the min cost to a certain node) if necessary
//    3.4 push the new cost to the pq if necessary
// 4. repeat 2 ~ 3 until all nodes are visited

// priority_queue  O(n^2logn) + cache to store the min cost to each node
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

// 2. Kruskal's Algorithm: Union-Find
// finding the MST in a graph(connect all nodes with the minimum cost)
// also used for:
// checking if 2 nodes in different sets,
// no cycle is formed when a new edge is added...
//
// Need 2 helper functions:
// 1. find (find root of a certain node)
// 2. unionSets (merge 2 sets into 1 by defining x's root = y)
class Solution {
private:
  // 2 helper functions of Union-Find
  // 1. find the root(parent) node of node x
  int find(vector<int> &parent, int x) {
    if (parent[x] == x)
      return x;
    // else
    parent[x] = find(parent, parent[x]);
    return parent[x];
  }

  // 2. merge 2 sets by setting x's root as y's child
  void unionSets(vector<int> &parent, int x, int y) {
    parent[find(parent, x)] = find(parent, y);
  }

public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();

    // parent[i] records the root node of node i
    vector<int> parent(n);
    // init the parent, make each node's parent as itself
    for (int i = 0; i < points.size(); i++) {
      parent[i] = i;
    }

    // {cost between x and y, {node x, node y}}
    vector<pair<int, pair<int, int>>> edges;
    // fill in the edges
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        // manhattan dist
        int cost =
            abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        edges.push_back({cost, {i, j}});
      }
    }

    // sort the cost from small to big
    sort(edges.begin(), edges.end());

    int ans = 0;
    // count the number of connected edges, should be n - 1
    int count = 0;

    for (auto i : edges) {
      int cost = i.first;
      int x = i.second.first;
      int y = i.second.second;

      // if x and y are not connected = they don't share the same root
      if (find(parent, x) != find(parent, y)) {
        // connect x and y = let them share the same root
        unionSets(parent, x, y);
        ans += cost;
        count++;
      }

      // if already have all nodes connected
      if (count == n - 1)
        break;
    }

    return ans;
  }
};
