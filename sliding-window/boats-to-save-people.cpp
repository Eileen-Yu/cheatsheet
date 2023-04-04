// https://leetcode.com/problems/boats-to-save-people/description/
// sliding window
class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end(), greater<>());
    int ans = 0;
    int n = people.size();
    // two pointers, sliding window
    int i = 0, j = n - 1;
    while (i <= j) {
      // only 1 people left
      if (i == j) {
        ans++;
        break;
      }
      // get a matching pair
      if (people[i] + people[j] <= limit) {
        ans++;
        i++;
        j--;
      }
      // not get a matching pair, need 1 boat for this person
      else {
        ans++;
        i++;
      }
    }

    return ans;
  }
};
