// https://leetcode.com/problems/reorganize-string/description/
// 1. pq: sort by decreasing frequency
// so that we can try to use the most frequent char as much as possible
class Solution {
public:
  string reorganizeString(string s) {
    // record the frequency of each char
    unordered_map<char, int> mp;
    for (auto i : s) {
      mp[i]++;
    }

    // sort the chars by decreasing frequency
    // e.g 2--a, 1--b
    priority_queue<pair<int, char>> pq;
    for (auto [c, freq] : mp) {
      pq.push({freq, c});
    }

    string ans = "";

    // while there are at least 2 various chars
    while (pq.size() >= 2) {
      // get the two most frequent chars, append them to the ans
      auto [freq1, c1] = pq.top();
      pq.pop();
      ans += c1;

      auto [freq2, c2] = pq.top();
      pq.pop();
      ans += c2;

      // if there's left char, push them back to the pq to re-sort
      if (freq1 - 1 > 0)
        pq.push({freq1 - 1, c1});
      if (freq2 - 1 > 0)
        pq.push({freq2 - 1, c2});
    }

    // if there are pending chars(same char, but may duplicated)
    if (!pq.empty()) {
      auto [freq, c] = pq.top();
      // if there are >= 2 duplicated chars left, impossible to reorganize the
      // string
      if (freq > 1)
        return "";

      // else
      ans += c;
    }

    return ans;
  }
};
