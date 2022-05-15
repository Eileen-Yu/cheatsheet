//  https://leetcode.com/problems/network-delay-time/
//
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<pair<int, int>>> neighs(n + 1);
    for (auto q : times) { // hash for neighbors of each node
      neighs[q[0]].push_back({q[1], q[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq; // every time find least cost
    vector<int> rslt(n + 1,
                     INT_MAX); // hash record cost to each node, start from '1'
    pq.push({0, k});           // min cost : endpoint, push start point(k)
    rslt[k] = 0;

    while (!pq.empty()) {
      int n = pq.top().second; // current node
      pq.pop();

      for (auto q : neighs[n]) {
        // if accumulative cost to this node + cost to its neighbor < recorded
        // cost to the neighbor
        if (rslt[n] + q.second < rslt[q.first]) {
          rslt[q.first] = rslt[n] + q.second;
          pq.push({rslt[q.first], q.first}); // min cost : endpoint, for pq
        }
      }
    }

    int ans = *max_element(rslt.begin() + 1,
                           rslt.end()); // max_element return a pointer
    return ans == INT_MAX ? -1 : ans;   // if INT_MAX, not every node reachable
  }
};
