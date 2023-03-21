// https://leetcode.com/problems/design-browser-history/description/
// Doubly Linked List
// Doubly Linked List
class Node {
public:
  Node *next;
  Node *prev;
  string data;

  Node(string url) {
    next = nullptr;
    prev = nullptr;
    data = url;
  }
};

class BrowserHistory {
public:
  Node *head;

  BrowserHistory(string homepage) { head = new Node(homepage); }

  void visit(string url) {
    Node *tmp = head;
    head->next = new Node(url);
    head = head->next;
    head->prev = tmp;
  }

  string back(int steps) {
    while (steps-- && head->prev) {
      head = head->prev;
    }
    return head->data;
  }

  string forward(int steps) {
    while (steps-- && head->next) {
      head = head->next;
    }
    return head->data;
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
