// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/
// hash map to put people of the same groupSize together
// then split them into subgroups if necessary
// trick: split vector into subvectors
class Solution {
public:
  vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
    // {groupSize, {id1, id2...}}
    map<int, vector<int>> mp;
    // fill in the map
    for (int i = 0; i < groupSizes.size(); i++) {
      mp[groupSizes[i]].push_back(i);
    }

    vector<vector<int>> ans;

    // loop the map
    for (auto i : mp) {
      int sz = i.first;
      vector<int> ids = i.second;

      // if exactly 1 group, directly push
      if (ids.size() == sz)
        ans.push_back(ids);

      // else, need to split into smaller groups
      else if (ids.size() > sz) {
        // each time take `sz` units of elements
        for (int j = sz; j <= ids.size(); j += sz) {
          // substract the sub vector
          vector<int> tmp(ids.begin() + j - sz, ids.begin() + j);
          ans.push_back(tmp);
        }
      }
    }

    return ans;
  }
};
