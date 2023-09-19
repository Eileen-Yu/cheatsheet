// https://leetcode.com/problems/find-the-duplicate-number/description
// we can solve the duplication problem by building a linked list with cycle
// then apply the hare & tortoise algorithm
class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    // hare tortoise algorithm to detect cycle in a linked list
    // (as there's duplication, there must be a cycle)
    // make 0 as the head of the list
    int slow = 0, fast = 0;

    // until slow and fast meet, means we are at a node in the cycle
    do {
      // each time slow moves 1 step
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    // move slow to the head
    slow = 0;
    // both slow & fast move 1 step each time
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};
