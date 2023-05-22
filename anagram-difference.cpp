// similar to
// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
// input: a = ['tea', 'tea', 'act']
//        b = ['ate', 'toe', 'acts']
// return [0,1,-1]

// map to record char's frequency
vector<int> getMinimumDifference(vector<string> a, vector<string> b) {
  // length of a,b
  int n = a.size();
  // key: char, val: frequency
  map<char, int> mp;
  vector<int> ans(n);

  for (int i = 0; i < n; i++) {
    // refresh the map
    mp.clear();

    string word1 = a[i];
    string word2 = b[i];

    if (word1.length() != word2.length()) {
      ans[i] = -1;
      continue;
    }
    // abb, bbc
    for (auto x : word1) {
      mp[x]++;
    }
    // {a:1, b:2}

    for (auto y : word2) {
      mp[y]--;
    }
    // {a:1, b:0, c:-1}

    int sum = 0;
    for (auto item : mp) {
      if (item.second != 0) {
        sum += abs(item.second);
      }
    }

    ans[i] = sum / 2;
  }

  return ans;
}
