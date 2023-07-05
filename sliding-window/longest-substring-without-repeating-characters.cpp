// https://leetcode.com/problems/longest-substring-without-repeating-characters/
//  sliding window + hash map to record the frequency of chars
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    // record the frenquency of each character in the window range
    map<char, int> mp;
    int n = s.length();
    // left side of the sliding window
    int l = 0;
    int ans = 0;

    // extend the window by moving the right side
    for (int r = 0; r < n; r++) {
      char cur = s[r];
      mp[cur]++;

      // shorten the window if there is repeated chars
      while (mp[cur] > 1) {
        // update the map as these elements are excepted from the window
        mp[s[l]]--;
        l++;
      }

      // update the ans
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};

// 2. use map to keep the state
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    map<char, int> b;
    int i = 0;
    int j = 0;
    int rslt = 0;

    while (j < s.length()) {
      if (b.count(s[j]) > 0) {
        i = max(i, b[s[j]] + 1);
      }

      rslt = max(rslt, j - i + 1);
      b[s[j]] = j;
      j++;
    }

    return rslt;
  }
};

// 2. Use new string to keep the state
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int i = 0;
    int j = 0;
    string news = "";
    int rslt = 0;

    while (j < s.length()) {
      news = s.substr(i, j - i + 1);
      int newRslt = news.length();
      rslt = max(rslt, newRslt);

      if ((j + 1) >= s.length())
        break;

      if (news.find(s[j + 1]) == string::npos) {
        j++;
      }

      else {
        while (news.find(s[j + 1]) != string::npos) {
          i++;
          news = s.substr(i, j - i + 1);
        }
        j++;
      }
    }

    return rslt;
  }
};
