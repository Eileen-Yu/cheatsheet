// https://leetcode.com/problems/sort-array-by-parity/

// 2 pointer, in-place
class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &nums) {
    for (int i = 0, j = 0; j < nums.size(); j++) {
      if (nums[j] % 2 == 0)
        swap(nums[i++], nums[j]);
    }
    return nums;
  }
};

// pick odd,even then merge
class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &nums) {
    vector<int> odd;
    vector<int> even;
    vector<int> ans;

    for (auto q : nums) {
      if (q % 2 == 0)
        even.push_back(q);
      else
        odd.push_back(q);
    }

    for (auto q : even)
      ans.push_back(q);

    for (auto q : odd)
      ans.push_back(q);

    return ans;
  }
};
