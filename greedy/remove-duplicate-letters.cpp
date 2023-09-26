// https://leetcode.com/problems/remove-duplicate-letters/description
// 1. frequency + visited, each time check if this char has been added to the
// ans + where to put it
class Solution {
public:
  string removeDuplicateLetters(string s) {
    // hash table to count the frequency of each char
    // so that we can know once a char has been erased (to meet the
    // lexicographical order), can we append it later
    vector<int> freq(26, 0);
    // fill in the hash table
    for (auto i : s)
      freq[i - 'a']++;

    // mark if we have added a char into the ans
    vector<bool> visited(26, false);
    string ans;

    // loop each char in string
    for (auto i : s) {
      int curIdx = i - 'a';
      // update the frequency to record how many this char are left in the
      // string
      freq[curIdx]--;

      // if this char already added to the ans before, continue
      if (visited[i - 'a'])
        continue;

      // else, need to add it to the ans
      // then, decide where to put it
      // if 1. ans is not empty
      // 2. this char has a smaller lexico order
      // 3. the last char will occur later
      while (ans.length() > 0 && i < ans.back() &&
             freq[ans.back() - 'a'] >= 1) {
        // mark it as unused
        visited[ans.back() - 'a'] = false;
        // remove the last char (will add it later)
        ans.pop_back();
      }

      // add this current char
      ans.push_back(i);
      // mark it as used
      visited[curIdx] = true;
    }

    return ans;
  }
};
