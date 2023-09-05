// https://leetcode.com/problems/copy-list-with-random-pointer/
// deep copy of linked list with multiple pointers:

// 1. use 2 loops + map:
// first loop to follow the ->next, create all nodes, put {originalNode,
// copiedNode} into map second loop to build ->random link by utilizing the map
class Solution {
public:
  Node *copyRandomList(Node *head) {
    // special case
    if (!head)
      return nullptr;

    // map to store {original node, copied node}
    unordered_map<Node *, Node *> mp;

    // idx to loop the original linked list
    Node *tmp = head;
    // new head of the copied linked list
    Node *newHead = nullptr;
    // record the last copied node
    Node *last = nullptr;

    // 1. the first loop to build the ->next link
    // loop the original linked list
    // in this loop we have created all nodes
    while (tmp) {
      // copy it
      Node *newNode = new Node(tmp->val);
      // add it to the map
      mp[tmp] = newNode;

      // connect it to the last copied node / it's the newHead
      if (!newHead)
        newHead = newNode;
      else
        last->next = newNode;

      // update this node as the last node, for the next loop
      last = newNode;

      // move to the next node
      tmp = tmp->next;
    }

    // 2. the second loop to build the ->random link
    // loop the copied linked list & original linked list at the meantime
    tmp = head;
    Node *copy = newHead;

    while (tmp) {
      // if the original->random is not nullptr
      // cuz we maintain the map of {originalNode, copiedNode}, we can utilize
      // it here
      if (tmp->random)
        copy->random = mp[tmp->random];
      else
        copy->random = nullptr;

      // move to the next
      tmp = tmp->next;
      copy = copy->next;
    }

    return newHead;
  }
};

// 2. 1 loop, create next & random nodes at the same time,
// but need to check if a certain node has been copied by utilizing the map each
// time
class Solution {
public:
  Node *copyRandomList(Node *head) {
    // special case
    if (!head)
      return nullptr;

    // store the new created nodes {originalNode, copiedNode}
    unordered_map<Node *, Node *> mp;

    Node *dummy = new Node(-10001);
    Node *tmp = head;
    Node *last = dummy;

    // loop the original linked list
    while (tmp) {
      // copy of the current node 'tmp'
      Node *newNode;
      // if this node hasn't been copied yet
      if (mp.find(tmp) == mp.end()) {
        // copy it
        newNode = new Node(tmp->val);
        // add it to the map
        mp[tmp] = newNode;
      }
      // if already copied, get it
      else
        newNode = mp[tmp];
      // connect the current node with the last node
      last->next = newNode;

      // copy the random node this current node points to
      if (tmp->random) {
        // copy of the current node->random
        Node *randomNode;
        // check if it's already been created yet
        if (mp.find(tmp->random) == mp.end()) {
          // if not, copy it
          randomNode = new Node(tmp->random->val);
          // add it to map
          mp[tmp->random] = randomNode;
        }

        // else if already created, get it
        else
          randomNode = mp[tmp->random];

        // connect the current node with the random node
        newNode->random = randomNode;
      }

      // if original->random = nullptr
      else
        newNode->random = nullptr;

      // record this one as the last
      last = newNode;
      // move to the next node
      tmp = tmp->next;
    }

    return dummy->next;
  }
};
