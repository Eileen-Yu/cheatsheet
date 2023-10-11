// https://leetcode.com/problems/4sum/description/
// similar idea to 3sum: fix 2 points, slide the other 2 as a range
// but need to pay attention to edge cases & overflow
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    // sort from small to big, for sliding the 2 pointers later
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;

    // the range of the first element
    for (int i = 0; i < n - 3; i++) {
      // skip the duplication
      if (i - 1 >= 0 && nums[i] == nums[i - 1])
        continue;

      // the range of the second element
      for (int j = i + 1; j < n - 2; j++) {
        // skip the duplication
        // * cannot use if (j - 1 > 0 && nums[j] == nums[j-1]), this will mix
        // with the outter loop e.g {2,2,2,2,2} target = 8
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;

        // the 2 pointers to move
        int k = j + 1, l = n - 1;

        while (k < l) {
          // except define `tmp` as long long, also needs to transfer the
          // original int(nums[i], etc) to long long
          long long tmp = (long long)nums[i] + (long long)nums[j] +
                          (long long)nums[k] + (long long)nums[l];

          if (tmp == target) {
            ans.push_back({nums[i], nums[j], nums[k], nums[l]});
            // try the next quadruplets
            k++;
            // skip the duplication
            while (k < l && nums[k] == nums[k - 1])
              k++;
          }

          else if (tmp > target) {
            l--;
            // skip the duplication
            while (k < l && nums[l] == nums[l + 1])
              l--;
          }

          else if (tmp < target) {
            k++;
            // skip the duplication
            while (k < l && nums[k] == nums[k - 1])
              k++;
          }
        }
      }
    }

    return ans;
  }
};
