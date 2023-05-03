// https://leetcode.com/problems/find-the-difference-of-two-arrays/

// 1. upgraded map version
class Solution {
public:
  // return elements only appear in n1
  vector<int> helper(vector<int> &n1, vector<int> &n2) {
    unordered_map<int, int> mp;
    // put all element in n1 to the map
    for (auto i : n1) {
      mp[i]++;
    }

    // erase the repeat elements both in n1 & n2
    for (auto i : n2) {
      auto it = mp.find(i);
      if (it != mp.end())
        mp.erase(it);
    }

    // return the distinct elements
    vector<int> ans;
    for (auto i : mp) {
      ans.push_back(i.first);
    }

    return ans;
  }

  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> ans;
    ans.push_back(helper(nums1, nums2));
    ans.push_back(helper(nums2, nums1));

    return ans;
  }
};

// 2. plain map version
class Solution {
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
    map<int, int> mp1;
    map<int, int> mp2;

    for (auto i : nums1) {
      mp1[i]++;
    }

    for (auto i : nums2) {
      mp2[i]++;
    }

    vector<int> v1;
    for (auto i : mp1) {
      int key = i.first;
      // find the distinct element
      if (mp2.find(key) == mp2.end())
        v1.push_back(key);
    }

    vector<int> v2;
    for (auto j : mp2) {
      int key = j.first;
      // find the distinct element
      if (mp1.find(key) == mp1.end())
        v2.push_back(key);
    }

    vector<vector<int>> ans;
    ans.push_back(v1);
    ans.push_back(v2);
    return ans;
  }
};

// ugly one by loop
class Solution {
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> ans;
    vector<int> new1;
    vector<int> new2;

    for (int i = 0; i < nums1.size(); i++) {
      bool exists = std::find(std::begin(new1), std::end(new1), nums1[i]) !=
                    std::end(new1);
      if (exists == true)
        continue;

      int f = 0;
      for (int j = 0; j < nums2.size(); j++) {
        if (nums1[i] == nums2[j])
          f = 1;
      }
      if (f != 1)
        new1.push_back(nums1[i]);
    }

    for (int i = 0; i < nums2.size(); i++) {
      bool exists = std::find(std::begin(new2), std::end(new2), nums2[i]) !=
                    std::end(new2);
      if (exists == true)
        continue;

      int f = 0;
      for (int j = 0; j < nums1.size(); j++) {
        if (nums2[i] == nums1[j])
          f = 1;
      }
      if (f != 1)
        new2.push_back(nums2[i]);
    }

    ans.push_back(new1);
    ans.push_back(new2);
    return ans;
  }
};
