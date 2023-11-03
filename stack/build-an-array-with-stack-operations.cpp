// https://leetcode.com/problems/build-an-array-with-stack-operations/
// stack simulation
class Solution {
public:
  vector<string> buildArray(vector<int> &target, int n) {
    stack<int> st;
    // idx to loop target
    int j = 0;
    vector<string> ans;

    // loop from 1 to n
    for (int i = 1; i <= n; i++) {
      // push this element into stack
      st.push(i);
      ans.push_back("Push");

      // if this element is in target
      if (target[j] == st.top()) {
        // move idx to check the next target
        j++;

        // if all target has met, directly return
        if (j >= target.size())
          return ans;
        // else continue to check the next element
        else
          continue;
      }

      else { // if this element is not in target
        // pop it
        st.pop();
        ans.push_back("Pop");
      }
    }

    return {};
  }
};
