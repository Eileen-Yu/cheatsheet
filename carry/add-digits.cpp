// https://leetcode.com/problems/add-digits/description/
//

// 1. queue
class Solution {
public:
  int addDigits(int num) {
    queue<int> q;
    q.push(num);

    while (q.front() / 10 > 0) {
      int tmp = q.front();
      q.pop();
      int next = 0;

      while (tmp != 0) {
        next += tmp % 10;
        tmp /= 10;
      }

      q.push(next);
    }

    return q.front();
  }
};

// 2. recursion
