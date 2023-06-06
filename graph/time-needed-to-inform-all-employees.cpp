// https://leetcode.com/problems/time-needed-to-inform-all-employees/description/
// 1. BFS, use pair to record time needed till this level
class Solution {
public:
  int numOfMinutes(int n, int headID, vector<int> &manager,
                   vector<int> &informTime) {
    // adjacency matrix
    // idx: manager
    // value: [[staff1, staff2], ....]
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      if (i == headID)
        continue;
      adj[manager[i]].push_back(i);
    }

    // {time to reach current node, curNode}
    queue<pair<int, int>> q;
    q.push({0, headID});
    int ans = 0;

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        auto [time, curNode] = q.front();
        q.pop();

        // update ans as the maximum we need till this level
        ans = max(ans, time);

        for (auto neighbor : adj[curNode]) {
          q.push({time + informTime[curNode], neighbor});
        }
      }
    }

    return ans;
  }
};
