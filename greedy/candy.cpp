// https://leetcode.com/problems/candy/description/
// greedy algorithm: 2 pass
// makes choices that seem optimal at the moment
class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    // record the candies that each children get
    // init with 1 because each child would get at least 1 candy
    vector<int> candies(n, 1);

    // 1. loop from left to right,
    // to ensure children with the higher rate can get more candies than the
    // left neighbor
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1])
        candies[i] = candies[i - 1] + 1;
    }

    // 2. loop from right to left,
    // to ensure children with the higher rate can get more candies than the
    // right neighbor
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1])
        candies[i] = max(candies[i], candies[i + 1] + 1);
    }

    // sum up candies to get the ans
    int ans = 0;
    for (auto i : candies)
      ans += i;

    return ans;
  }
};
