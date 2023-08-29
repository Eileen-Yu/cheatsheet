// https://leetcode.com/problems/minimum-penalty-for-a-shop/
// 1. prefix-sum + suffix-sum
// translate the problem to --> min sum (# of 'N' before i + # of 'Y' >= i)
// *prefix-sum needs to be careful about the matching relationship & idx!!!
class Solution {
public:
  int bestClosingTime(string customers) {
    int n = customers.size();
    // record the number of 'N' before i-th hour
    // this represent shop open but no customer
    // range:[0, n], 0 is the base case
    vector<int> prefix(n + 1, 0);
    // start from 1, because no elements before 0
    for (int i = 1; i <= n; i++) {
      // # of 'N' before i-th element = # of 'N' in [0, i-1]
      // = # of 'N' before (i-1)th element + if 'i-1'th element is 'N
      prefix[i] = prefix[i - 1] + (customers[i - 1] == 'N');
    }

    // record the number of 'Y' >= i-th element
    // this represent shop close but customer come
    vector<int> suffix(n + 1, 0);
    // start from n-1, because n-1 itself shoule be included
    for (int i = n - 1; i >= 0; i--) {
      // # of 'Y' >= i-th element = # of 'Y' in [i, n-1]
      // = # of 'Y' >= (i+1)th element + if i-th element is 'Y'
      suffix[i] = suffix[i + 1] + (customers[i] == 'Y');
    }

    int penalty = INT_MAX;
    int ans = 0;
    // try to close the shop at i-th ~ n-th hour
    for (int i = 0; i <= n; i++) {
      // penalty = # of 'N' before i + # of 'Y' >= i
      int tmp = prefix[i] + suffix[i];

      if (tmp < penalty) {
        penalty = tmp;
        ans = i;
      }
    }

    return ans;
  }
};

// 2. plain version, O(n^2), would TLE
class Solution {
public:
  int bestClosingTime(string customers) {
    int n = customers.size();
    int penalty = INT_MAX, ans = INT_MAX;

    // try to close the shop at 0th ~ nth hour
    for (int i = 0; i <= n; i++) {
      // penalty if close at i-th hour
      int tmp = 0;

      // loop each hour's customer
      for (int j = 0; j < n; j++) {
        // if open but no customer
        if (customers[j] == 'N' && j < i)
          tmp++;
        // if close but customer show
        else if (customers[j] == 'Y' && j >= i)
          tmp++;
      }

      if (tmp < penalty) {
        // record the minimum penalty until now
        penalty = tmp;
        // record the corresponding hour
        ans = i;
      }
    }

    return ans;
  }
};
