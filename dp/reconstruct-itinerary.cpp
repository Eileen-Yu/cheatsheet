// https://leetcode.com/problems/reconstruct-itinerary/description/
// Semi Euler Path: all nodes indegree = outdegree, except for:
// start: outdegree = indegree + 1
// end: indegree = outdegree + 1
// use DFS(recursion) to find the path
// trick: sort dst in adj from big to small, and each time pick the back one,
// this can ensure we always pick the smaller one
class Solution {
public:
  // adjacency matrix
  // e.g: {
  //       "JFK": {"SFO", "ATL"},
  //       "ATL": {"JFK", SFO"},
  //        ...
  //      }
  unordered_map<string, vector<string>> adj;
  vector<string> ans;

  // recursion for dfs
  void dfs(string from) {
    // need to use & to modify on the original dst vector
    vector<string> &to = adj[from];
    // for each neighbor
    while (!to.empty()) {
      string next = to.back();
      to.pop_back();
      dfs(next);
    }

    // push this node to the ans
    // since it's recursion, it would be in the reverse order
    ans.push_back(from);
  }

  vector<string> findItinerary(vector<vector<string>> &tickets) {
    // fill in the adj matrix
    for (auto i : tickets) {
      string from = i[0];
      string to = i[1];
      adj[from].push_back(to);
    }

    // sort the destionations from big to small lexical order,
    // so that each time we can first get smaller dst from the end
    // need to use & to modify on the original dst vector
    for (auto &[_, to] : adj) {
      sort(to.rbegin(), to.rend());
    }

    // apply dfs recursion, JFK is the fixed start
    dfs("JFK");

    // adjust the order in the ans
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
