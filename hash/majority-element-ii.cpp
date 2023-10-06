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

// 3. find majority element --> Moore Voting Algo
// > n / 3 --> at most 2 majority elements
class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    // since the majority is > n/3, means we would at most have 2 majority
    // elements
    int candidate1 = 0, candidate2 = 0;
    int count1 = 0, count2 = 0;

    // first loop to find the possible 2 majority elements
    for (auto i : nums) {
      // first, check if this elements can match with 2 candidates
      if (i == candidate1)
        count1++;
      else if (i == candidate2)
        count2++;
      // then, check if it can be a new candidate
      else if (count1 == 0) {
        candidate1 = i;
        count1++;
      } else if (count2 == 0) {
        candidate2 = i;
        count2++;
      }
      // else if this element doesn't match either candidate and neither count
      // is zero
      else {
        count1--;
        count2--;
      }
    }

    // now we have the 2 possible candidates, we need to have the exact count of
    // them
    count1 = 0, count2 = 0;

    for (auto i : nums) {
      if (i == candidate1)
        count1++;
      else if (i == candidate2)
        count2++;
    }

    vector<int> ans;
    int n = nums.size();
    if (count1 > n / 3)
      ans.push_back(candidate1);
    if (count2 > n / 3)
      ans.push_back(candidate2);

    return ans;
  }
};
