// https://leetcode.com/problems/design-browser-history/description/

// Approach 2 : stack

class BrowserHistory {
public:
  stack<string> history;
  stack<string> future;

  BrowserHistory(string homepage) { visit(homepage); }

  void visit(string url) {
    history.push(url);
    // clear the future stack
    future = stack<string>();
  }

  string back(int steps) {
    // at least 1 history and 1 current
    // top of history is current page
    while (history.size() > 1 && steps--) {
      string tmp = history.top();
      future.push(tmp);
      history.pop();
    }
    return history.top();
  }

  string forward(int steps) {
    // at least 1 future to forward
    while (!future.empty() && steps--) {
      string tmp = future.top();
      history.push(tmp);
      future.pop();
    }
    return history.top();
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
