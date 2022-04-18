// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
//

class Solution {
public:
  int minimumRounds(vector<int> &tasks) {
    map<int, int> mp;
    int ans = 0;

    for (auto q : tasks) {
      mp[q]++;
    }

    for (auto q : mp) {
      if (q.second == 1)
        return -1;
      if (q.second % 3 == 0)
        ans += q.second / 3;
      else
        ans += q.second / 3 + 1;
    }

    return ans;
  }
};
