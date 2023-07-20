// https://leetcode.com/problems/asteroid-collision/
// 1. stack to play eliminating
class Solution {
public:
  vector<int> asteroidCollision(vector<int> &a) {
    int n = a.size();
    stack<int> s;

    for (int i = 0; i < n; i++) {
      int cur = a[i];
      // if it's ->, definitely wouldn't cause collision
      if (cur > 0) {
        s.push(cur);
        continue;
      }

      // else if cur < 0
      // when would cause the collision to remove the last one:
      // only when -> <- and the cur is bigger
      while (!s.empty() && s.top() > 0 && s.top() < -cur) {
        s.pop();
      }
      // if they are of the same size, no one exists, so use `else if`
      if (!s.empty() && s.top() == -cur)
        s.pop();
      // when the new one may exist when the direction is <-
      // 1. stack is empty
      // 2. the last one is in the same direction(also <-)
      else if (s.empty() || s.top() < 0)
        s.push(cur);
    }

    vector<int> ans;
    while (!s.empty()) {
      ans.push_back(s.top());
      s.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// 2. plain version, would TLE
// because only -> <- would collision, while <- -> would not
class Solution {
public:
  vector<int> asteroidCollision(vector<int> &a) {
    stack<int> s;
    int n = a.size();
    s.push(a[0]);

    for (int i = 1; i < n; i++) {
      int cur = a[i];

      while (!s.empty()) {
        if (cur == 0)
          break;
        int t = s.top();
        // if the same direction
        if (cur * t > 0) {
          break;
        }

        // if different directions
        else if (t > 0 && cur < 0) {
          s.pop();
          // if the size are equal
          if (abs(cur) == abs(t))
            cur = 0;
          // the bigger one can survive
          else
            cur = abs(cur) > abs(t) ? cur : t;
        }
      }

      if (cur == 0)
        continue;
      else
        s.push(cur);
    }

    vector<int> ans;
    while (!s.empty()) {
      ans.push_back(s.top());
      s.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
