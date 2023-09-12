// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
// priority queue: try to eliminate duplicated frequencies from big to small
class Solution {
public:
  int minDeletions(string s) {
    // {char, frequency}
    unordered_map<char, int> mp;
    for (auto c : s) {
      mp[c]++;
    }

    // sort the frequencies from big to small
    priority_queue<int> pq;
    for (auto i : mp) {
      pq.push(i.second);
    }

    int ans = 0;
    while (pq.size() > 1) {
      int tmp = pq.top();
      pq.pop();

      int next = pq.top();
      // if there are duplicated frequency
      if (next == tmp && next != 0) {
        // delete 1
        ans++;
        // update with the new frequency
        pq.push(next - 1);
      }
    }

    return ans;
  }
};
