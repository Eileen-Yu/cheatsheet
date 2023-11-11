// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs
// find the start num + adj matrix + dfs
// 1. use visited
class Solution {
public:
  void dfs(unordered_map<int, vector<int>> &adj,
           unordered_map<int, bool> &visited, vector<int> &ans, int cur) {
    // loop each neighbor of the current number
    for (auto neighbor : adj[cur]) {
      // if visited, skip
      if (visited[neighbor])
        continue;

      // else
      // 1. mark as visited
      visited[neighbor] = true;
      // 2. put this number to ans
      ans.push_back(neighbor);
      // 3. find the next number
      dfs(adj, visited, ans, neighbor);
    }
  }

  vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
    // adjacency matrix
    unordered_map<int, vector<int>> adj;
    // count the frequency of each element to find the start point: it would
    // only appear once
    unordered_map<int, int> count;

    // fill up the adj & count frequency by looping each pair
    for (auto i : adjacentPairs) {
      int from = i[0];
      int to = i[1];

      // bidirectional
      adj[from].push_back(to);
      adj[to].push_back(from);

      count[from]++;
      count[to]++;
    }

    int start;
    for (auto i : count) {
      if (i.second == 1)
        start = i.first;
    }

    // mark if a number has been visited
    unordered_map<int, bool> visited;
    // mark the start as visited
    // since the number can be negative(-1), use hash map rather than hash table
    visited[start] = true;

    vector<int> ans;
    // push the start to ans
    ans.push_back(start);

    dfs(adj, visited, ans, start);

    return ans;
  }
};
