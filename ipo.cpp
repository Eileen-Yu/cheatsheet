// https://leetcode.com/problems/ipo/description/
// Time complexity:
// nlogn(sort the vector) + klogn(K loop * insert into pq would take logn)

class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits,
                           vector<int> &capital) {
    // capital:profits
    vector<pair<int, int>> record;
    // number of projects
    int n = profits.size();
    for (int i = 0; i < n; i++) {
      record.push_back({capital[i], profits[i]});
    }
    // sort by capital
    sort(record.begin(), record.end());

    // record loop to which project
    int i = 0;
    // always get the largest profit
    priority_queue<int> pq;
    int ans = 0;
    // choose k projects
    while (k--) {
      // for every project that meet the capital requirement
      while (i < n && record[i].first <= w) {
        // put the profit into pq
        pq.push(record[i].second);
        // check the next project
        i++;
      }
      // if no matching project, means the current capital is not enough any
      // more
      if (pq.empty())
        break;

      // for all those projects that can be chosen with current capital,
      // (this includes the previous one because w would only ++)
      // only choose the one with largest profit
      w += pq.top();
      pq.pop();
    }

    return w;
  }
};
