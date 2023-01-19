// https://leetcode.com/problems/subarray-sums-divisible-by-k/
//
//
// loop, but will TimeLimitExceed in some cases
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      int sum;
      int ans = 0;
      int len = nums.size();

      // deal with special case
      if (len == 1) {
        if (nums[0] % k == 0) return 1;
      }

      for (int i = 0; i < len - 1; i++) {
        sum = nums[i];
        if (sum % k == 0) ans++;
        
        for (int j = i+1; j < len; j++) {
          sum += nums[j];
          if (sum % k == 0) ans++;
        }
      }

      // deal with the last element
      if (nums[len-1] % k == 0) ans++;

      return ans;
    }
};


// prefix sum
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      map<int,int> mp; // remainder, cnt
      mp[0] = 1; // assume the first element can be divided by k
      int sum = 0;
      int ans = 0;
      int remainder = 0;

      for (auto i : nums) {
        sum += i;
        remainder = (sum % k + k) % k; // for sum < 0
        // if array A and B have the same sum remainder of K, then A-B can be divided by K
        ans += mp[remainder];
        mp[remainder]++;
      }

      return ans;
    }
};

// replace map with index to improve the performance
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      vector<int> idx(k,0); // idx: remainder, value: cnt
      idx[0] = 1; // assume the first element can be divided by k
      int sum = 0;
      int ans = 0;
      int remainder = 0;

      for (auto i : nums) {
        sum += i;
        remainder = (sum % k + k) % k; // for sum < 0
        // if array A and B have the same sum remainder of K, then A-B can be divided by K
        ans += idx[remainder];
        idx[remainder]++;
      }

      return ans;
    }
};

