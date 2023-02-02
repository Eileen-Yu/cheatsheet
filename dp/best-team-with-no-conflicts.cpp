// https://leetcode.com/problems/best-team-with-no-conflicts/description/
//
//
// 1. dp
class Solution {
public:
  int bestTeamScore(vector<int> &scores, vector<int> &ages) {
    vector<pair<int, int>> record; // <ages, scores>
    int n = scores.size();
    for (int i = 0; i < n; i++) {
      record.push_back({ages[i], scores[i]});
    }
    // sort based on age
    sort(record.begin(), record.end());

    int ans = 0;
    // record the best score if take current(dp[i]) player(ensure no conflict)
    int dp[n];
    for (int i = 0; i < n; i++) {
      dp[i] = record[i].second;
      for (int j = 0; j < i; j++) {
        // if the younger player has fewer/equal score with current player
        if (record[j].second <= record[i].second) {
          // record[j] is a 'set' with no conflict
          dp[i] = max(dp[i], record[i].second + dp[j]);
        }
      }
      ans = max(ans, dp[i]);
    }

    return ans;
  }
};

// 2. backtracking, would Time Limit Exceed in some cases:
class Solution {
public:
  void recursion(vector<pair<int, int>> &record, vector<pair<int, int>> &tmp,
                 int curTotal, int &total, int idx) {
    // when to stop:
    if (idx >= record.size())
      return;

    // if the player's age >= the last player and his score >= current player
    if (tmp.empty() || record[idx].second >= tmp.back().second) {
      // take this player
      tmp.push_back(record[idx]);
      curTotal += record[idx].second;
      total = max(total, curTotal);
      recursion(record, tmp, curTotal, total, idx + 1);
      // not take this player
      curTotal -= tmp.back().second;
      tmp.pop_back();
    }
    recursion(record, tmp, curTotal, total, idx + 1);
  }

  int bestTeamScore(vector<int> &scores, vector<int> &ages) {
    vector<pair<int, int>> record; // <ages, scores>
    for (int i = 0; i < ages.size(); i++) {
      record.push_back({ages[i], scores[i]});
    }
    // sort based on age
    sort(record.begin(), record.end());

    vector<pair<int, int>> tmp;
    int total = 0;
    int curTotal = 0;
    int idx = 0;
    recursion(record, tmp, curTotal, total, idx);
    return total;
  }
};
