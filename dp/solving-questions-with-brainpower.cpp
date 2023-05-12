// https://leetcode.com/problems/solving-questions-with-brainpower/description/
// 1. recursion (backtracking), would TLE
class Solution {
public:
  long long recursion(vector<vector<int>> &questions, int idx) {
    // when to return
    if (idx >= n)
      return 0;

    int score = questions[idx][0];
    int steps = questions[idx][1];
    int skipTo = idx + steps + 1;

    // take / not take this question
    return max(score + recursion(questions, skipTo),
               recursion(questions, idx + 1));
  }

  long long mostPoints(vector<vector<int>> &questions) {
    return recursion(questions, 0);
  }
};

// OR use tmp + ans to record
class Solution {
public:
  void recursion(vector<vector<int>> &questions, int idx, int &ans, int &tmp) {
    // when to return
    if (idx >= questions.size())
      return;

    int score = questions[idx][0];
    int skip = questions[idx][1];
    // 1. if we take this question
    tmp += score;
    ans = max(ans, tmp);
    recursion(questions, idx + skip + 1, ans, tmp);
    // 2. if we don't take this question
    tmp -= score;
    recursion(questions, idx + 1, ans, tmp);
  }

  long long mostPoints(vector<vector<int>> &questions) {
    int ans = 0, tmp = 0;
    recursion(questions, 0, ans, tmp);
    return ans;
  }
};

// 2. memoization (recursion, divide the whole problem into small subproblems
// duing the recursion)
// use the table to avoid duplicate calculation
class Solution {
public:
  long long recursion(vector<vector<int>> &questions, int idx,
                      vector<long long> &dp) {
    // when to return
    if (idx >= questions.size())
      return 0;

    // already calculated
    if (dp[idx] != -1)
      return dp[idx];

    int score = questions[idx][0];
    int steps = questions[idx][1];
    int skipTo = idx + steps + 1;

    // take / not take this question
    return dp[idx] = max(score + recursion(questions, skipTo, dp),
                         recursion(questions, idx + 1, dp));
  }

  long long mostPoints(vector<vector<int>> &questions) {
    long n = questions.size();
    // dp[i] represents the max accumulative score we may get at i-th question
    // from top to bottom
    vector<long long> dp(n, -1);
    return recursion(questions, 0, dp);
  }
};
