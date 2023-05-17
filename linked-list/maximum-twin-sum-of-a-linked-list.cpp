// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
// 1. stack, store value in the reverse sequence
// Time Complexity : O(N) , Space Complexity : O(N)
class Solution {
public:
  int pairSum(ListNode *head) {
    // stack to store value in the reverse consequence
    stack<int> s;
    ListNode *tmp = head;

    // fill the stack with values
    while (tmp) {
      s.push(tmp->val);
      tmp = tmp->next;
    }

    int ans = INT_MIN;
    int sum = 0;
    tmp = head;

    // loop the linked list to get value of the first half, and add it with the
    // second half value stored in the stack
    while (tmp) {
      sum = tmp->val + s.top();
      s.pop();
      ans = max(ans, sum);
      tmp = tmp->next;
    }

    return ans;
  }
};

// 2. tortoise and hare to find the middle node + reverse the second half linked
// list Time Complexity : O(N) , Space Complexity : O(1)
class Solution {
public:
  ListNode *reverse(ListNode *head) {
    ListNode *cur = head;
    ListNode *prev = nullptr;
    ListNode *nextNode;

    while (cur) {
      // record the next based on the original direction, or it may lose later
      nextNode = cur->next;
      // reverse the direction of currecnt node
      cur->next = prev;
      // move forward
      prev = cur;
      cur = nextNode;
    }

    // update the head as the one in the last originally
    return prev;
  }

  int pairSum(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    // use tortoise and hare to find the middle node
    while (slow->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    // even, so the start node of the second half is this one
    slow = slow->next;

    ListNode *right = reverse(slow);
    int ans = INT_MIN;
    // because the reverse() would break the connect between the two halves
    while (right) {
      // add twins
      ans = max(ans, head->val + right->val);
      head = head->next;
      right = right->next;
    }

    return ans;
  }
};

// 3. extra space: use vector to record value of each node
// Time Complexity : O(N) , Space Complexity : O(N)
class Solution {
public:
  int pairSum(ListNode *head) {
    vector<int> record;

    while (head) {
      record.push_back(head->val);
      head = head->next;
    }

    int ans = INT_MIN;
    int n = record.size();

    for (int i = 0; i <= n / 2 - 1; i++) {
      int sum = record[i] + record[n - 1 - i];
      ans = max(ans, sum);
    }

    return ans;
  }
};
