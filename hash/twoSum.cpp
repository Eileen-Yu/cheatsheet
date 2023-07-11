// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
// 1. hash map to record the previously looped elements
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // value: idx
    map<int, int> mp;
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      int left = target - nums[i];
      // if the complement already exists
      if (mp.find(left) != mp.end()) {
        ans.push_back(i);
        ans.push_back(mp[left]);
        break;
      }

      mp[nums[i]] = i;
    }

    return ans;
  }
};

// 2. brute force
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      int cur = nums[i];
      int left = target - cur;

      for (int j = i + 1; j < n; j++) {
        if (nums[j] == left) {
          ans.push_back(i);
          ans.push_back(j);
          break;
        }
      }
    }

    return ans;
  }
};
