// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
//
// 2. indegree
class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
    // idx: node, value: indegree number
    vector<int> degree(n, 0);

    for (auto i : edges) {
      int to = i[1];
      degree[to]++;
    }

    vector<int> ans;
    // pick starting nodes, they are those with 0 indegree
    for (int i = 0; i < degree.size(); i++) {
      if (degree[i] == 0) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
