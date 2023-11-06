// https://leetcode.com/problems/find-the-winner-of-an-array-game/
// array
class Solution {
public:
  int getWinner(vector<int> &arr, int k) {
    // special case:
    // if k >= arr.size() - 1, ans must be the biggest element
    if (k >= arr.size() - 1)
      return *max_element(arr.begin(), arr.end());

    // idx to mark the winner of each round
    int win = 0;
    // count the number of win rounds
    int count = 0;

    // the compared item in each round
    for (int j = 1; j < arr.size(); j++) {
      // if the winner remains
      if (arr[win] > arr[j]) {
        // just increase the count
        count++;
      }

      // if there's a new winner
      else {
        // 1. update winner idx
        win = j;
        // 2. reset count
        count = 1;
      }

      // if meet the winning requirement
      if (count == k)
        return arr[win];
    }

    // if the game doesn't end when all elements have been looped over
    // the winner will still be the winner regardless the looping round
    return arr[win];
  }
};
