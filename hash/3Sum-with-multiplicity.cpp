// https://leetcode.com/problems/3sum-with-multiplicity/
// use map to record all the sum pairs before

// O(n^2)
class Solution {
public:
  int threeSumMulti(vector<int> &arr, int target) {
    // sum: frequency
    unordered_map<int, int> mp;
    int n = arr.size();
    int ans = 0;
    int MOD = 1e9 + 7;

    for (int i = 0; i < n; i++) {
      // add up all triplets till now
      // each time it must be a unique triplet as we have a new nums[i]
      ans = (ans + mp[target - arr[i]]) % MOD;

      // update the mp by adding this one
      for (int j = 0; j < i; j++) {
        mp[arr[j] + arr[i]]++;
      }
    }

    return ans;
  }
};
