// https://leetcode.com/problems/group-anagrams/description/
// anagram --> sort as they contain the same elements
// 1. need to return the original words --> copy + pair
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
