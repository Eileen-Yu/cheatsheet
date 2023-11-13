// https://leetcode.com/problems/sort-vowels-in-a-string/description/
// 1. store all the vowels + sorting
class Solution {
public:
  string sortVowels(string s) {
    // store all vowels
    vector<char> store;
    // store the idx of all vowels
    vector<int> idx;

    // put all vowels into store
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
          s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
          s[i] == 'o' || s[i] == 'u') {
        idx.push_back(i);
        store.push_back(s[i]);
      }
    }

    sort(store.begin(), store.end());

    for (int i = 0; i < idx.size(); i++) {
      s[idx[i]] = store[i];
    }

    return s;
  }
};
