// https://leetcode.com/problems/majority-element-ii/description/
// 1. hash map to record frequency of each element
// Time Complexity: O(n)
// Space Complexity: O(n) - Extra space is used to store counts in the map
class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {

    // element, frequency
    unordered_map<int, int> mp;
    for (auto i : nums)
      mp[i]++;

    vector<int> ans;
    for (auto i : mp) {
      if (i.second > nums.size() / 3)
        ans.push_back(i.first);
    }

    return ans;
  }
};

// 2. sorting
// Time Complexity: O(nlogn) - sorting
// Space Complexity: O(1) - only use constant extra space
class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int n = nums.size();
    // special case
    if (n == 1)
      return {nums[0]};

    // put all same elements together
    sort(nums.begin(), nums.end());
    vector<int> ans;

    // count of current element
    int c = 1;
    // the current element
    int tmp = nums[0];

    for (int i = 1; i < n; i++) {
      if (nums[i] == tmp)
        c++;

      else {
        if (c > n / 3)
          ans.push_back(tmp);
        // nums[i] is a new element
        tmp = nums[i];
        c = 1;
      }
    }

    // the final element
    if (c > n / 3)
      ans.push_back(tmp);

    return ans;
  }
};
