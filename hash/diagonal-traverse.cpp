// https://leetcode.com/problems/diagonal-traverse/submissions/
// hash map to group all elements on the same diagonal line (i+j is the same)
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    // all the elements on 1 diagonal line share the same sum of i + j
    // {sum of i & j, [nums[i][j], nums[i][j]....]}
    map<int, vector<int>> mp;
    // loop each cell to fill in the map
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        mp[i + j].push_back(mat[i][j]);
      }
    }

    vector<int> ans;
    // loop the map
    for (auto i : mp) {
      int sum = i.first;
      vector<int> tmp = i.second;
      // if sum is even, needs to reverse the elements
      if (sum % 2 == 0)
        reverse(tmp.begin(), tmp.end());

      // put all the elements in this group to the ans
      for (auto i : tmp)
        ans.push_back(i);
    }

    return ans;
  }
};
