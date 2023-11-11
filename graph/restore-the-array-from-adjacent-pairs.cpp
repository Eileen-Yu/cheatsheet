// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs
// find the start num + adj matrix + dfs
// 1. because each num in the middle will only have 2 neighbor,
// and the start / end would have 1 neighbor
// we don't need visited[] here
class Solution {
public:
  vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
    // adjacency matrix
    unordered_map<int, vector<int>> adj;

    // fill up the adj & count frequency by looping each pair
    for (auto i : adjacentPairs) {
      int from = i[0];
      int to = i[1];

      // bidirectional
      adj[from].push_back(to);
      adj[to].push_back(from);
    }

    vector<int> ans;

    // find the start
    for (auto i : adj) {
      // the head would only have 1 neighbor
      if (i.second.size() == 1) {
        // the first 2 nums in the ans can be found
        ans.push_back(i.first);
        ans.push_back(i.second[0]);
        break;
      }
    }

    // find the other nums
    // the size of the ans should = pair + 1
    while (ans.size() < adjacentPairs.size() + 1) {
      int last = ans[ans.size() - 1];
      int prev = ans[ans.size() - 2];
      // there would only be 2 possible neighbors of the current num
      // if the neighbor == prev, then it cannot be the next num
      int next = adj[last][0] == prev ? adj[last][1] : adj[last][0];
      // put the next into ans
      ans.push_back(next);
    }

    return ans;
  }
};

// 2. use visited
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
