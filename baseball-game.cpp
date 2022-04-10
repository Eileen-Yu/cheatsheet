// https://leetcode.com/problems/baseball-game/
//
class Solution {
public:
  int calPoints(vector<string> &ops) {
    vector<int> rd;
    int sum = 0, n = 0;

    for (auto q : ops) {
      if (q == "C")
        rd.pop_back();

      else if (q == "D") {
        n = rd.back();
        n = n * 2;
        rd.push_back(n);
      }

      else if (q == "+") {
        int a = rd.back();
        rd.pop_back();
        int b = rd.back();
        rd.push_back(a);
        int s = a + b;
        rd.push_back(s);
      }

      else {
        rd.push_back(stoi(q));
      }
    }

    for (int i = 0; i < rd.size(); i++) {
      sum += rd[i];
    }

    return sum;
  }
};
