// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-arra
// prefix sum to apply maths idea
// key formula: i'th index's Sum of Absolute Differences = Sum of Absolute
// Differences[ i-1 ] + i * (arr[i]-arr[i-1]) - (n-i) * (arr[i]-arr[i-1])

// e.g: [1,4,6,8,10]
// SAD for 6(idx = 2): 5,2,0,2,4
// SAD for 8(idx = 3): 7,4,2,0,2
// for the first 3 elements: + (8-6) * 3
// for the rest 2 elements: - (8-6) * 2

class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
    vector<int> ans;
    int n = nums.size();
    // get the base: SAD of the first element
    int base = 0;
    for (int i = 1; i < n; i++) {
      base += abs(nums[i] - nums[0]);
    }
    ans.push_back(base);

    // calculate the rest based on prefix sum
    for (int i = 1; i < n; i++) {
      // i * (nums[i] - nums[i-1]): add the increased differences on the left
      // side of the current element (n-i) * (nums[i] - nums[i-1]): substract
      // the decreased differences on the right side of the current
      // element(include current one)
      int tmp = ans.back() + i * (nums[i] - nums[i - 1]) -
                (n - i) * (nums[i] - nums[i - 1]);
      ans.push_back(tmp);
    }

    return ans;
  }
};
