// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
// greedy + sort: sort arrival time from small to big
class Solution {
public:
  int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
    // the time it would take each monster to arrive the city
    vector<double> time;

    for (int i = 0; i < dist.size(); i++) {
      // calculate time as double
      time.push_back(double(dist[i]) / speed[i]);
    }

    // sort time from small to big
    sort(time.begin(), time.end());

    // the first monster must can be fired
    int ans = 1;
    // record the current time (charge once after the first shot)
    int cur = 1;

    // loop from the second time
    for (int i = 1; i < time.size(); i++) {
      // if monster already reached the city, lose the game
      if (cur >= time[i])
        return ans;

      // else, can fire this monster
      ans += 1;
      // charge takes 1 min
      cur += 1;
    }

    // otherwise, all monsters can be fired
    return dist.size();
  }
};
