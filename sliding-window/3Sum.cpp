// https://leetcode.com/problems/3sum/description/
//
// 1. sliding window, each time fix 1 pointer, slide 2 pointers
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int len = nums.size();
    if (len < 3)
      return {};
    sort(nums.begin(), nums.end());
    if (nums[0] > 0)
      return {};

    vector<vector<int>> ans;
    // each time we fix i, move j / k based on the result
    for (int i = 0; i < len - 2; i++) {
      // jump the duplicate
      if (i >= 1 && nums[i] == nums[i - 1])
        continue;

      int j = i + 1;
      int k = len - 1; // start from the last element

      while (j < k) {
        if (nums[i] + nums[j] + nums[k] == 0) {
          ans.push_back({nums[i], nums[j], nums[k]});

          // continue to check the next pair
          j++;
          // jump the duplicate
          while (j < k && nums[j] == nums[j - 1])
            j++;
        }

        else if (nums[i] + nums[j] + nums[k] < 0) {
          j++;
          // jump the cuplicate
          while (j < k && nums[j] == nums[j - 1])
            j++;
        } else {
          k--;
          // jump the duplicate
          while (k > j && nums[k] == nums[k + 1])
            k--;
        }
      }
    }

    return ans;
  }
};

// 2. sort + hashMap
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int len = nums.size();
    if (len < 3)
      return {}; // special cases
    sort(nums.begin(), nums.end());
    if (nums[0] > 0)
      return {}; // no possibility to make sum = 0

    vector<vector<int>> ans;
    // to record the position of the last duplicate number to avoid duplicates
    unordered_map<int, int> mp;
    for (int i = 0; i < len; i++) {
      mp[nums[i]] = i;
    }

    for (int i = 0; i < len - 2; i++) {
      // no possibility to make sum = 0
      if (nums[i] > 0)
        break;

      for (int j = i + 1; j < len - 1; j++) {
        int third = -1 * (nums[i] + nums[j]);
        // if nums[k] exists and k > j
        if (mp.count(third) > 0 && mp[third] > j) {
          ans.push_back({nums[i], nums[j], third});
        }
        // jump to the last nums[j] to avoid duplicates
        j = mp[nums[j]];
      }
      // jump to the last nums[i] to avoid duplicates
      i = mp[nums[i]];
    }

    return ans;
  }
};
