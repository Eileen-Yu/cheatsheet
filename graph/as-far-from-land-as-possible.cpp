// https://leetcode.com/problems/as-far-from-land-as-possible/description/
//
// 1. BFS, convert the problem into:
// start from each land(1)
// try to reach the neighbor 0s
// then start from this 0, and repeat the step
// check when could turn all 0s into 1s
// the number of the iteration is the answer
// ref:
// https://leetcode.com/problems/as-far-from-land-as-possible/solutions/3166138/day-41-c-bfs-easiest-beginner-friendly-approach-o-n-2-time-and-o-n-2-approach/

class Solution {
public:
  int maxDistance(vector<vector<int>> &grid) {
    // copy the original grid, avoid changing the input param
    vector<vector<int>> visited = grid;
    // queue to implement BFS, store the vector of each node
    queue<pair<int, int>> q;
    int n = grid.size();

    // pick all the land as start nodes into queue
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        // push all land to the queue
        if (visited[i][j] == 1)
          q.push({i, j});
      }
    }

    // if no land / no water
    if (q.empty() || q.size() == n * n)
      return -1;
    // possible direction of each node, right, left, up, down
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int ans = 0;
    while (!q.empty()) {
      int size = q.size();
      // for each `layer`
      while (size--) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : dir) {
          int i = x + dx;
          int j = y + dy;
          // check not exceed the boundary
          if (i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == 0) {
            // mark as visited
            visited[i][j] = 1;
            q.push({i, j});
          }
        }
      }
      ans++;
    }

    // the last water would be visited but still in the queue, which have extra
    // 1 step so start from -1
    return ans - 1;
  }
}

// 2. pair to record the vector of each node
//    and loop to find the max in or min(nearest)
class Solution {
public:
  int maxDistance(vector<vector<int>> &grid) {
    // the vector of each water and land
    vector<pair<int, int>> zero; // water
    vector<pair<int, int>> one;  // land
    int n = grid.size();

    // record the vector
    // sample: 0: <0,1>, <1,0>...
    //         1: <0,0>, <0,2>...
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0)
          zero.push_back({i, j});
        else
          one.push_back({i, j});
      }
    }
    // if no land or water exists
    if (zero.empty() || one.empty())
      return -1;

    int ans = -1;
    // the distance of current water to certain land
    int tmp;
    // the nearest distance of current water to certain land
    int nearest;
    // for each water
    for (auto i : zero) {
      nearest = INT_MAX;
      // compare with each land
      for (auto j : one) {
        // calculate distance
        tmp = abs(i.first - j.first) + abs(i.second - j.second);
        // record the nearest distance of current 0 to certain 1
        nearest = min(nearest, tmp);
      }
      // record the maximum of all the nearest distance
      ans = max(ans, nearest);
    }

    return ans;
  }
};
