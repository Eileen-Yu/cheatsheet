// https://leetcode.com/problems/diagonal-traverse-ii/
// 1. BFS to put cells in to a queue
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &nums) {
    // BFS, {i, j}
    queue<pair<int, int>> q;
    // put the first cell into queue
    q.push({0, 0});

    int n = nums.size();
    vector<int> ans;

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      // put this cell into ans
      ans.push_back(nums[i][j]);

      // if the current cell is in the first column && not in the last row
      // put the cell directly below the current one to queue
      if (j == 0 && i < n - 1)
        q.push({i + 1, j});

      // if the current cell is not the last one in this row
      // put the right cell to the queue
      if (j < nums[i].size() - 1)
        q.push({i, j + 1});
    }

    return ans;
  }
};

// 2. use hash map to store the elements on the same diaginal line:
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
