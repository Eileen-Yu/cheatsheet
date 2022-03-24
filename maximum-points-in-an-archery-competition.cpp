// https://leetcode.com/problems/maximum-points-in-an-archery-competition/

#include <iostream>
#include <vector>
using namespace std;

int memo[12][10];

void displayMemo() {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 10; j++) {
      cout << memo[i][j] << " ";
    }
    cout << "\n\n";
  }
}

int dp(int turn, int restArrows, vector<int> &alice) {   // highest score for this turn
  if (turn == 12 || restArrows <= 0)
    return 0;

  if (memo[turn][restArrows] != -1)
    return memo[turn][restArrows];

  // get max score in case bob gives up this turn 
  int maxScore = dp(turn + 1, restArrows, alice);

  // get max score in case not give up this turn
  if (restArrows - alice[turn] > 0) {          // have to shoot aliceArrows[turn] + 1
    int scoreNotGiveup = dp(turn + 1, restArrows - alice[turn] - 1, alice) + turn; 
    maxScore = max(maxScore, scoreNotGiveup);  // whether to give up or not
  }

  memo[turn][restArrows] = maxScore;
  // cout << "turn: " << turn << ", restArrows: " << restArrows
       // << ", maxScore:" << maxScore << "\n";
  // displayMemo();
  return maxScore;
}

vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows) {
  memset(memo, -1, sizeof(memo));       // initialize the memo
  vector<int> ans(12, 0);
  int remainArrows = numArrows;
  for (int turn = 0; turn < 12; turn++) {
    if (dp(turn, numArrows, aliceArrows) !=      // if scores for two turns are the same, means give up
        dp(turn + 1, numArrows, aliceArrows)) {
      ans[turn] = aliceArrows[turn] + 1;
      numArrows -= ans[turn];
      remainArrows -= ans[turn];
    }
  }
  ans[0] += remainArrows;
  return ans;
}

int main() {

  cout << "\n";
  vector<int> aliceArrows = {1, 1, 0, 1, 0, 0, 2, 1, 0, 1, 2, 0};
  int n = 9;

  for (int i = 0; i < aliceArrows.size(); i++) {
    cout << aliceArrows[i] << " ";
  }
  cout << "\n";

  vector<int> ans = maximumBobPoints(n, aliceArrows);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
