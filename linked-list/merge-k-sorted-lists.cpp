// https://leetcode.com/problems/merge-k-sorted-lists/description/
// Merge sort + linked list loop
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
  ListNode *merge(vector<ListNode *> &lists, ListNode *left, ListNode *right) {
    ListNode *dummy = new ListNode(-1);
    ListNode *tmp = dummy;
    while (left != nullptr && right != nullptr) {
      if (left->val < right->val) {
        tmp->next = left;
        tmp = tmp->next;
        left = left->next;
      } else {
        tmp->next = right;
        tmp = tmp->next;
        right = right->next;
      }
    }

    // which means right is empty
    while (left != nullptr) {
      tmp->next = left;
      tmp = tmp->next;
      left = left->next;
    }

    // which means left is empty
    while (right != nullptr) {
      tmp->next = right;
      tmp = tmp->next;
      right = right->next;
    }

    return dummy->next;
  }

  ListNode *mergeSort(vector<ListNode *> &lists, int start, int end) {
    // when to return: only 1 element remains
    if (start == end) {
      return lists[start];
    }
    // divide
    int mid = start + (end - start) / 2;
    ListNode *left = mergeSort(lists, start, mid);
    ListNode *right = mergeSort(lists, mid + 1, end);
    // conquer
    return merge(lists, left, right);
  }

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty())
      return nullptr;

    return mergeSort(lists, 0, lists.size() - 1);
  }
};
