// https://leetcode.com/problems/3sum-closest/description/
// fix 1 pointer, slide the other 1 pointers
// each time update the ans with the one closet to the target
// very similar to https://leetcode.com/problems/3sum/description/

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    // init the ans
    int ans = nums[0] + nums[1] + nums[2];

    // loop for the first element
    for (int i = 0; i < n - 2; i++) {
      // skip the duplication
      if (i >= 1 && nums[i] == nums[i - 1])
        continue;

      // slide the second & third element
      int j = i + 1;
      int k = n - 1;

      while (j < k) {
        int tmp = nums[i] + nums[j] + nums[k];
        // if tmp is closer, update the ans
        if (abs(target - tmp) < abs(target - ans))
          ans = tmp;

        // if ans is exactly the target, directly return
        if (ans == target)
          return ans;

        // else, decide which to move: j OR j based on the tmp
        // 1. if tmp > target, need to make sum smaller, so move k
        if (tmp > target) {
          k--;
          // skip the duplication
          while (k > j && nums[k] == nums[k + 1])
            k--;
        }
        // 2. if tmp < target, need to make sum bigger, so move j
        else if (tmp < target) {
          j++;
          // skip the duplication
          while (j < k && nums[j] == nums[j - 1])
            j++;
        }
      }
    }

    return ans;
  }
};
