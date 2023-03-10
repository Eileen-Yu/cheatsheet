// https://leetcode.com/problems/linked-list-random-node/description/
// vector to record + rand % n to get random number
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  // record value of each node
  vector<int> record;

  Solution(ListNode *head) {
    while (head != nullptr) {
      record.push_back(head->val);
      head = head->next;
    }
  }

  int getRandom() {
    // generate randome number between 0 to n-1 (n is the size of record)
    int i = rand() % record.size();
    return record[i];
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
