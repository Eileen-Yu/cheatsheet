// https://leetcode.com/problems/verifying-an-alien-dictionary/description/

class Solution {
public:
  bool isAlienSorted(vector<string> &words, string order) {
    map<char, int> mp; // character: position
    for (int i = 0; i < order.size(); i++) {
      mp[order[i]] = i;
    }

    // loop every word and compare with the previous one
    for (int i = 1; i < words.size(); i++) {
      int j = 0;
      // loop every char of the word
      for (j; j < min(words[i].size(), words[i - 1].size()); j++) {
        // compare each char
        if (mp[words[i][j]] < mp[words[i - 1][j]])
          return false;
        // once the char of the latter is `bigger`, stop, to the next word
        if (mp[words[i][j]] > mp[words[i - 1][j]])
          break;
      }
      // special case, char > nil
      if (j == words[i].size() && words[i - 1][j])
        return false;
    }

    return true;
  }
};
