// https://leetcode.com/problems/path-with-minimum-effort/description/

// Dijkstra's: finding the shortest paths from a single source vertex to all
// other vertices in a weighted, directed graph (implementation is bit similar
// to Prim's, but Prim is for MST(connect nodes) in an undirected graph)

// Both Dijkstra & Prim use:
// 1. pq to choose the next `best` edge / node
// 2. greedy algorithms, making local optimum choices at each step in the hopes
// of finding a global optimum

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int m = heights.size();
    int n = heights[0].size();

    // {cost, {x, y}}, represent the cost to reach the cell(x,y)
    // sort by cost from small to big, so to ensure we always try to pick the
    // path with the smaller cost
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<>>
        pq;
    // cache[i][j] records the minimum cost to reach this cell
    vector<vector<int>> cache(m + 1, vector<int>(n + 1, INT_MAX));

    // init the start, need 0 cost to reach the first cell
    cache[0][0] = 0;
    pq.push({0, {0, 0}});

    // 4 directions
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Dijkstra's: each time pick the minimum cost to reach a certain cell
    // goal: update cost cache
    while (!pq.empty()) {
      auto [cost, pos] = pq.top();
      pq.pop();
      int i = pos.first;
      int j = pos.second;

      // if the cost to reach this cell {i,j} is bigger than the cache
      if (cost > cache[i][j])
        continue;

      // else, update cache
      cache[i][j] = cost;

      // loop 4 neighbors
      for (auto dir : dirs) {
        int x = i + dir[0];
        int y = j + dir[1];

        // our of boundary
        if (x < 0 || y < 0 || x >= m || y >= n)
          continue;

        // else, calculate the cost to reach the new cell{x,y} from the current
        // cell{i,j}
        int newCost = max(cache[i][j], abs(heights[x][y] - heights[i][j]));

        // check if needs to update the cache & pq
        if (newCost < cache[x][y]) {
          cache[x][y] = newCost;
          pq.push({newCost, {x, y}});
        }
      }
    }

    return cache[m - 1][n - 1];
  }
};
