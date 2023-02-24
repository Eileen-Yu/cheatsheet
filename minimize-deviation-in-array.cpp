// https://leetcode.com/problems/minimize-deviation-in-array/description/
//
// Time complexity: nlogn (there are n elements,
// for each element, it takes logn to insert into the set)
//
class Solution {
public:
  int minimumDeviation(vector<int> &nums) {
    // ordered, unique
    set<int> st;
    for (auto i : nums) {
      // if i is odd, make it even
      // this operation tries to increase the minimum value
      // because even num can only be decreased!
      if (i % 2 == 1)
        i *= 2;
      // put the num into set
      st.insert(i);
    }

    // set initial ans as max - min num in the set
    // set.begin() return an iterator, so to get the value need *
    int ans = *st.rbegin() - *st.begin();
    // while the max in the set is even, try to reduce it
    // until it becomes an odd, so that it can only increase
    // this tries to decrease the maximum value
    while (*st.rbegin() % 2 == 0) {
      // remove the max from the set
      int tmp = *st.rbegin();
      st.erase(tmp);
      // devide the max by 2 and insert it back to the set
      st.insert(tmp / 2);
      // update the minDeviation
      ans = min(ans, *st.rbegin() - *st.begin());
    }

    return ans;
  }
};
