// https://leetcode.com/problems/maximum-number-of-coins-you-can-get
// sort to make sure bob always get the least piles
// then I can get the second largest each time
class Solution {
public:
  int maxCoins(vector<int> &piles) {
    // sort from small to big
    sort(piles.begin(), piles.end());

    int n = piles.size();
    int ans = 0;

    // give bob the smallest elements, so start from idx n / 3
    // alice and I get biggest and second biggest each time, so += 2
    for (int i = n / 3; i < n; i += 2) {
      ans += piles[i];
    }

    return ans;
  }
};
