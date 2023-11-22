// https://leetcode.com/problems/diagonal-traverse-ii/
// use hash map to store the elements on the same diaginal line:
// sum of i,j are the same
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &nums) {
    // {sum of i and j, [nums[i][j], nums[i][j]....]}
    map<int, vector<int>> mp;
    // loop each cell to fill up the map
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums[i].size(); j++) {
        mp[i + j].push_back(nums[i][j]);
      }
    }

    vector<int> ans;
    // loop the map
    for (auto i : mp) {
      vector<int> tmp = i.second;
      // fill the ans from bottom to top
      for (int i = tmp.size() - 1; i >= 0; i--) {
        ans.push_back(tmp[i]);
      }
    }

    return ans;
  }
};
