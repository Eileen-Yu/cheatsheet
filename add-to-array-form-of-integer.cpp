// https://leetcode.com/problems/add-to-array-form-of-integer/description/
// 1. take k as carry (math skill??)
class Solution {
public:
  vector<int> addToArrayForm(vector<int> &num, int k) {
    // avoid change original input
    vector<int> ans = num;
    for (int i = num.size() - 1; i >= 0; i--) {
      ans[i] += k;
      // k is the carry
      k = ans[i] / 10;
      // the digit for this certain position
      ans[i] %= 10;
    }
    // if there's carry to deal with
    while (k > 0) {
      // insert to the highest position
      ans.insert(ans.begin(), k % 10);
      k /= 10;
    }

    return ans;
  }
};

// 2. loop every digit of int to convert the int to array form
// and then add two array forms
class Solution {
public:
  // loop every digit of int to convert it into array-form
  void intToArray(int n, vector<int> &karray) {
    if (n > 10) {
      intToArray(n / 10, karray);
    }
    if (n == 10)
      karray.push_back(1);
    karray.push_back(n % 10);
  }

  vector<int> addToArrayForm(vector<int> &num, int k) {
    vector<int> karray;
    intToArray(k, karray);

    // avoid change the original input
    vector<int> ans;
    int carry = 0;

    int ln = num.size(), lk = karray.size();
    int i = 0;

    // add two array forms
    // e.g: [1,2,0,0] + [3,4]
    while (i < ln || i < lk || carry) {
      int x = 0, y = 0;
      if (i < ln)
        x = num[ln - i - 1];
      if (i < lk)
        y = karray[lk - i - 1];
      ans.push_back((x + y + carry) % 10);
      carry = (x + y + carry) / 10;
      i++;
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
}
