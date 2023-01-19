// https://leetcode.com/problems/3sum/description/
//
//
//  sort + hashMap
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

// sliding window, 2-pointer trick
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
    for (int i = 0; i < len - 2; i++) {
      // jump the duplicate
      if (i != 0 && nums[i] == nums[i - 1])
        continue;
      int j = i + 1;
      int k = len - 1; // start from the last element
      while (j < k) {
        if (nums[i] + nums[j] + nums[k] == 0) {
          ans.push_back({nums[i], nums[j], nums[k]});
          j++;
          // jump the duplicate
          while (j < k && nums[j] == nums[j - 1])
            j++;
        } else if (nums[i] + nums[j] + nums[k] < 0)
          j++;
        else
          k--;
      }
    }

    return ans;
  }
};
