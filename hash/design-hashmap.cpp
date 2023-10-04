// https://leetcode.com/problems/design-hashmap/\
// simple hash table, very similar to https://leetcode.com/problems/design-hashset/

class MyHashMap {
public:
  // hash table
  vector<int> arr;

  MyHashMap() {
    // init the table size & no values by default
    // key's range: [0,10^6]
    arr = vector<int>(1000001, -1);
  }

  void put(int key, int value) { arr[key] = value; }

  int get(int key) { return arr[key]; }

  void remove(int key) { arr[key] = -1; }
};
