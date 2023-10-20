// https://leetcode.com/problems/flatten-nested-list-iterator/
// 1. use stack to flatten the nestedList on the fly
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
  stack<NestedInteger> st;

  NestedIterator(vector<NestedInteger> &nestedList) {
    // push all nestedList items in reverse order
    for (int i = nestedList.size() - 1; i >= 0; i--) {
      st.push(nestedList[i]);
    }
  }

  // already ensure the top must be a integer
  int next() {
    int ans = st.top().getInteger();
    st.pop();
    return ans;
  }

  bool hasNext() {
    // if the stack is not empty, must have the next
    while (!st.empty()) {
      NestedInteger tmp = st.top();
      // if it's a single integer, directly return true
      if (tmp.isInteger())
        return true;

      // else, need to flatten it
      vector<NestedInteger> list = tmp.getList();
      // pop this list from stack
      st.pop();
      // push integers into stack in reverse order
      for (int i = list.size() - 1; i >= 0; i--) {
        st.push(list[i]);
      }
    }

    // if the stack is empty, no next
    return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
