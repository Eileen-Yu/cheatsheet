// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description
// 1. k most --> priority_queue
class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    int m = mat.size();
    int n = mat[0].size();

    // {count of 1's, idx of row}, sort from small to big
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // push elements to the pq
    for (int i = 0; i < m; i++) {
      int c = 0;

      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 1)
          c++;
      }

      pq.push({c, i});
    }

    vector<int> ans;
    // pop k weakest rows
    while (k-- && !pq.empty()) {
      auto [count, idx] = pq.top();
      pq.pop();

      ans.push_back(idx);
    }

    return ans;
  }
};
