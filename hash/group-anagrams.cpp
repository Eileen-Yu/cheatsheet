// https://leetcode.com/problems/group-anagrams/description/
// anagram --> sorting as they contain the same elements
// 1. hash map + copy to generate groups
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    // {anagram after sort, {original word1, original word2,....}}
    unordered_map<string, vector<string>> mp;

    // generate each group
    // e.g {aet: {eat, tea, ate}}
    for (auto i : strs) {
      string copy = i;
      sort(copy.begin(), copy.end());
      mp[copy].push_back(i);
    }

    // push each group into ans
    vector<vector<string>> ans;
    for (auto i : mp) {
      ans.push_back(i.second);
    }

    return ans;
  }
};

// 2. need to return the original words --> copy + pair
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    // {after sort, original word}
    vector<pair<string, string>> v;
    for (auto i : strs) {
      string copy = i;
      sort(copy.begin(), copy.end());
      v.push_back({copy, i});
    }

    // sort by the word after sorting
    sort(v.begin(), v.end());

    vector<vector<string>> ans;
    // 1 pattern of anagram
    string tmp = v[0].first;
    // 1 anagram group
    vector<string> group;

    // loop each pair
    for (auto i : v) {
      if (i.first == tmp) {
        group.push_back(i.second);
      }

      // else, we meet a new group
      else {
        // put the last group into ans
        ans.push_back(group);

        // empty the group
        group.clear();
        // update the new group
        group.push_back(i.second);

        // update the pattern
        tmp = i.first;
      }
    }

    // push the last group into ans
    ans.push_back(group);

    return ans;
  }
};
