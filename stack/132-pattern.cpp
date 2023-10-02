// https://leetcode.com/problems/132-pattern/
// monotonic stack: all elements in stack from small to big

class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    // a monotonic stack, all top elements < bottom elements
    stack<int> st;
    // the '2' in 132, set to INT_MIN to let the first element to be pushed into
    // stack
    int third = INT_MIN;

    // loop from end to begin
    for (int i = nums.size() - 1; i >= 0; i--) {
      // when to return: if we already have '2', '3', and we now find '1'
      // compare with `third`, because once nums[i] < third, it must also < '3'
      if (nums[i] < third)
        return true;

      // else, if we find a new '3'
      // use 'while' so that we can make '2' as big as possible
      // also, by this, we can ensure all elements in the stack is from small to
      // big (monotonic stack)
      while (!st.empty() && nums[i] > st.top()) {
        // the old '3' becomes a valid '2'
        // so we have '3' and '2' now
        third = st.top();
        st.pop();
      }

      st.push(nums[i]);
    }

    return false;
  }
};
