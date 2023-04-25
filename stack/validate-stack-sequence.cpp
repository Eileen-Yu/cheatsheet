// https://leetcode.com/problems/validate-stack-sequences/description/
//
// simulate stack:
// To check whether it is valid == to check if all pending pop can be done

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> s;
    // since push.size == pop.size
    int n = pushed.size();

    // idx to loop pushed, popped
    int i = 0, j = 0;

    // if there is pending pop
    while (j < n) {
      // if stack is empty and there is pending push, push first
      if (s.empty() && i < n) {
        s.push(pushed[i]);
        i++;
      }
      // else if stack is empty and there is no pending push, break
      else if (s.empty() && i >= n)
        break;

      // if stack is not empty
      int tmp = s.top();
      // check if top is current pending pop
      if (tmp == popped[j]) {
        // if is, pop
        s.pop();
        j++;
      } else if (i < n) {
        // if not, and there is pending push, push
        s.push(pushed[i]);
        i++;
      } else
        break; // if not and there is no pending push, break
    }

    // if all pending pop can be conducted, return true
    if (j >= n)
      return true;

    return false;
  }
};
