// https://leetcode.com/problems/linked-list-cycle-ii/description/
//  Floyd's Cycle-Finding algorithm
//  AKA Hare-Tortoise
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
      // Move the slow pointer one step
      // and the fast pointer two steps at a time
      slow = slow->next;
      fast = fast->next->next;
      // If the pointers meet, there is a cycle in the linked list
      if (slow == fast) {
        // Reset the slow pointer to the head
        slow = head;
        // move both pointers one step at a time
        // until they meet again.
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        // where they meet is the starting point of the cycle.
        return slow;
      }
    }
    // if the fast pointer reach the end without meeting the slow
    // there is no cycle
    return nullptr;
  }
};
