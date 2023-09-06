// https://leetcode.com/problems/split-linked-list-in-parts/description/
// trick to split linked list:
// 1. let end = tmp
// 2. tmp = tmp->next
// 3. end->next = nullptr
// step 2,3 cannot be swapped
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
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    // count the number of nodes
    int n = 0;
    ListNode *tmp = head;
    while (tmp) {
      n++;
      tmp = tmp->next;
    }

    // the average of each part
    int ave = n / k;
    // the additional nodes shoule be assigned to the first several parts
    // in summary:
    // # in the first `more` parts: ave + 1
    // # in the rest parts: ave
    int more = n % k;

    vector<ListNode *> ans(k);

    // count the number of parts till now
    int part = 0;

    tmp = head;

    // loop each node
    while (tmp) {
      // this tmp is the head of this part
      ans[part] = tmp;

      // only when ave > 0, need to aggregate some nodes together
      // else, this tmp should be a sole node, directly jump to the below logic
      if (ave > 0) {
        // `nodes` count the number of nodes in the current part
        // fisrt aggregate `ave` nodes together
        // and check if need 1 more node in the first `more` parts
        for (int nodes = 0; nodes < ave - 1 + (part < more); nodes++) {
          tmp = tmp->next;
        }
      }

      // split at this end node
      ListNode *end = tmp;
      // the new start of the next part
      tmp = tmp->next;
      // end this part
      end->next = nullptr;

      // a new part generated, needs to update the count
      part++;
    }

    return ans;
  }
};
