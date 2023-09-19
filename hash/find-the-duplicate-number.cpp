// https://leetcode.com/problems/find-the-duplicate-number/description/
// This problem can also be solved by binary search & linked list & bit
// 1. most direct way: use map
class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    // {num, frequency}
    unordered_map<int, int> mp;

    for (auto i : nums) {
      mp[i]++;
    }

    for (auto i : mp) {
      if (i.second > 1)
        return i.first;
    }

    return -1;
  }
};

// 2. optimum: hash table
class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int n = nums.size();
    // hash table:
    // idx: num, value: frequency
    vector<int> hash(n);

    for (auto i : nums)
      hash[i]++;

    for (int i = 0; i < hash.size(); i++) {
      if (hash[i] > 1)
        return i;
    }

    return -1;
  }
};
