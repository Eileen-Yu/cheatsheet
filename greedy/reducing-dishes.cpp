// https://leetcode.com/problems/reducing-dishes/description/
// greedy: try to make the ans++ until reach the max, then it would reduce --

class Solution {
public:
  int maxSatisfaction(vector<int> &satisfaction) {
    // sort the satisfaction in desecnding order
    // always take the dish with the most satisfaction first
    // then see if there is chance to increase the overall k(ans) with second,
    // third..
    sort(satisfaction.begin(), satisfaction.end(), greater<int>());
    int sum = 0, ans = 0;
    for (int i = 0; i < satisfaction.size(); i++) {
      sum += satisfaction[i];
      // this would only reduce the overall k
      // and since the latter would be even smaller,
      // so we break here
      if (sum < 0)
        break;
      // samely perform satisfaction[i] * time[i]
      ans += sum;
    }

    return ans;
  }
};
