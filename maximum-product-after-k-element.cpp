// https://leetcode.com/problems/maximum-product-after-k-increments/

class Solution {
public:
  int maximumProduct(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0)
        break;
      nums[i] = 1;
      k -= 1;
    }

    if (k < 0)
      return 0; // must be at least 1 '0'

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto q : nums)
      pq.push(q);

    while (k > 0) { // add 1 to the smallest number
      int n = pq.top() + 1;
      k--;
      pq.pop();
      pq.push(n);
    }

    long long ans = 1, mod = 1e9 + 7;

    while (!pq.empty()) {
      ans *= pq.top();
      pq.pop();
      ans = ans % mod;
    }

    return ans;
  }
};
