// https://leetcode.com/problems/design-hashset/
// this is very similar to
// https://leetcode.com/problems/design-hashmap/description

// 1. use vector to implement hash table
class MyHashSet {
public:
  vector<bool> ans;

  MyHashSet() {
    ans.resize(1e6 + 1, false); // all initialize to false
  }

  void add(int key) { ans[key] = true; }

  void remove(int key) { ans[key] = false; }

  bool contains(int key) { return ans[key]; }
};

// 2. use set (seems a built-in hash table)
class MyHashSet {
public:
  unordered_set<int> st;

  MyHashSet() { st = unordered_set<int>(); }

  void add(int key) { st.insert(key); }

  void remove(int key) { st.erase(key); }

  bool contains(int key) { return st.find(key) == st.end() ? false : true; }
};
