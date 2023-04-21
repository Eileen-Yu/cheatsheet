// https://leetcode.com/problems/minimize-maximum-of-array/description/
// binary search(try every ans) + maths
class Solution {
public:
  bool isValid(int target, vector<int> &nums) {
    // special case
    // ans should be >= original max element in the array
    if (nums[0] > target)
      return false;

    long long prev = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      // how much need to increase
      long long diff = target - prev;
      // update value of current element (because it needs to decrease)
      prev = nums[i] - diff;
      // if value of current element is bigger than the supposed max
      if (prev > target)
        return false;
    }

    return true;
  }

  int minimizeArrayValue(vector<int> &nums) {
    // set the left & right end of binary search
    // the ans is between 0 and max of the elements
    int left = 0, right = *max_element(nums.begin(), nums.end());
    while (left < right) {
      int mid = left + (right - left) / 2;
      // if valid, try to find smaller ans as we are seeking for the minimize
      // maximum
      if (isValid(mid, nums))
        right = mid;
      else
        left = mid + 1;
    }
    // return the smallest maximum
    return right;
  }
}

// 2. Prefix Sum + Average (maths)
class Solution {
public:
  int minimizeArrayValue(vector<int> &nums) {
    // sum to store all prefix sum
    long long sum = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      long long aveVal = ceil(sum / (i + 1.0));
      ans = max(ans, aveVal);
    }

    return ans;
  }
};
