// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/
// hash table to count frquency + sort to eliminate duplicates from big to small
class Solution {
public:
  int minDeletions(string s) {
    // hash table to count the frequency of a ~ z
    vector<int> hash(26, 0);
    for (auto c : s) {
      hash[c - 'a']++;
    }

    // as we need to eliminate duplicated frequencies, so sort and start from
    // the bigger ones
    sort(hash.begin(), hash.end());
    int ans = 0;

    // from big to small
    for (int i = 24; i >= 0; i--) {
      // no frequency any longer as we have sorted the hash, just break the loop
      if (hash[i] == 0)
        break;

      // if there are duplicates
      // >=: in case 2, 2, 2
      if (hash[i] >= hash[i + 1]) {
        int tmp = hash[i];
        // update the frequency, as we need it to be minimum, so make it 1 less
        // than the larger one and it can at most be reduced to 0
        hash[i] = max(0, hash[i + 1] - 1);
        // calculate the reduction of this time
        ans += tmp - hash[i];
      }
    }

    return ans;
  }
};
