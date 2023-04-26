// https://leetcode.com/problems/simplify-path/description/

// stack to go up level

class Solution {
public:
  string simplifyPath(string path) {
    // stack to store dir names
    stack<string> s;
    string ans = "";

    // loop every char in the path
    for (int i = 0; i < path.length(); i++) {
      // if we meet /, just ignore
      if (path[i] == '/')
        continue;

      // get the dir name OR . OR ..
      string tmp;
      while (i < path.length() && path[i] != '/') {
        tmp += path[i];
        i++;
      }

      // just stay and do nothing
      if (tmp == ".")
        continue;

      // we need to go up a level
      // if stack is empty, means we are in the root dir, need to do nothing
      else if (tmp == "..") {
        if (!s.empty())
          s.pop();
      }

      // else we go to the specific dir
      else
        s.push(tmp);
    }

    if (s.empty())
      return "/";

    // else, we have a canoonical path
    while (!s.empty()) {
      // notice the sequence
      ans = '/' + s.top() + ans;
      s.pop();
    }

    return ans;
  }
};
