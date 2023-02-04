// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
//
//
// BFS:
class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    // Adjacency Matrix
    // idx: src, <dst, cost>
    vector<vector<pair<int, int>>> record(n);
    for (auto i : flights) {
      record[i[0]].push_back({i[1], i[2]});
    }

    // [dst, cost]
    queue<pair<int, int>> q;
    // start from the src
    q.push({src, 0});
    // idx: city; minCost[idx] cost
    vector<int> minCost(n, INT_MAX);
    int stop = 0;

    // k can be 0
    while (!q.empty() && stop <= k) {
      int size = q.size();
      // all possible bypass node
      while (size--) {
        auto [curNode, cost] = q.front();
        q.pop();
        // where to go, one pair presents one stop choice
        for (auto &[neighbor, price] : record[curNode]) {
          int accumCost = price + cost;
          if (accumCost < minCost[neighbor]) {
            // update the lowest cost to this dst(neighbor)
            minCost[neighbor] = accumCost;
            // if start from this neighbor, the current minCost is ...
            q.push({neighbor, minCost[neighbor]});
          }
        }
      }
      // to the next stop
      stop++;
    }
    if (minCost[dst] == INT_MAX)
      return -1;
    return minCost[dst];
  }
}
