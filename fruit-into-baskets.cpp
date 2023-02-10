// https://leetcode.com/problems/fruit-into-baskets/

// 1. sliding window
// This problem can be converted to:
// Finding the length of the longest subarray that contains <= 2 types of
// elements
class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int ans = 0;
    // record the fruit type and its frequency
    map<int, int> mp;
    // the left boundary, the start
    int i = 0;

    // j is the right boundary
    for (int j = 0; j < fruits.size(); j++) {
      mp[fruits[j]]++;

      // means more than 2 types
      if (mp.size() > 2) {
        // drop one type
        mp[fruits[i]]--;
        // if the frequency is 0, means there's no such type
        if (mp[fruits[i]] == 0)
          mp.erase(fruits[i]);
        // slide the window, cause we need consequent ones
        i++;

      } else {
        // there're <= 2 types
        ans = max(ans, j - i + 1);
      }
    }

    return ans;
  }
};

// 2. basic loop: will Time Limit Exceed in some cases
class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    if (fruits.size() == 1)
      return 1;

    int ans = 0;
    int f1 = -1, f2 = -1;
    for (int i = 0; i < fruits.size() - 1; i++) {
      int tmp = 0;
      f1 = fruits[i];
      f2 = -1;
      tmp++;

      for (int j = i + 1; j < fruits.size(); j++) {
        // meet the second type
        if (fruits[j] != f1 && f2 == -1) {
          f2 = fruits[j];
          tmp++;
          continue;
        }

        // meet the third type, stop
        if (fruits[j] != f1 && fruits[j] != f2)
          break;

        // either one of the two types
        tmp++;
      }
      ans = max(ans, tmp);
    }

    return ans;
  }
};
