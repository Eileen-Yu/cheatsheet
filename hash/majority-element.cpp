// https://leetcode.com/problems/majority-element/
// 1. hash map to count the frequency, then see if it's > n / 2 is applicable,
// omit here

// 2. sorting, as the majority element must would stand at nums[n/2]
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    return nums[nums.size() / 2];
  }
};

// 3. find the majority element --> Moore Voting Algorithm
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    // count of the current candidate
    int count = 0;
    // the assumed majority element
    int candidate = 0;

    // loop each element in the array
    for (auto i : nums) {
      // choose this element as the new candidate
      if (count == 0)
        candidate = i;

      // increase / decrease the count of the candidate
      if (i == candidate)
        count++;
      else
        count--;
    }

    return candidate;
  }
};
