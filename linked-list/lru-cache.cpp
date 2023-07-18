// https://leetcode.com/problems/lru-cache/description/
// list: doubly linked list
// feat: easy to insert at begin & pop the last
// so whenever a {key,value} is get / put, put it to the beginning of the list
// then the last element of the list would be the pair used least
class LRUCache {
public:
  // use doubly linked list to store the {key, val}
  // use list to easily insert at the begin & pop last one
  // always put the recently used one to the front
  list<pair<int, int>> dll;
  // {key: postion of the corresponding pair in the list}
  unordered_map<int, list<pair<int, int>>::iterator> mp;
  // capacity
  int s;

  LRUCache(int capacity) { s = capacity; }

  int get(int key) {
    // if the pair doesn't exist yet,
    // we don't need to concern about the exceeding, just return
    if (mp.find(key) == mp.end())
      return -1;

    // if the pair exists:
    // 1. get the pair position
    auto it = mp[key];
    // 2. get the pair
    auto [k, v] = *it;
    // 3. adjust the pair's position in the list to put it to the front
    dll.erase(it);
    dll.push_front({k, v});
    // 4. update the mp of the latest position
    mp[k] = dll.begin();
    // 5. return the value
    return v;
  }

  void put(int key, int value) {
    // if the key doesn't exist yet
    if (mp.find(key) == mp.end()) {
      // add it to the list
      dll.push_front({key, value});
      // add its position to the map
      mp[key] = dll.begin();
    }

    // if the key already exists
    else if (mp.find(key) != mp.end()) {
      // get the position
      auto it = mp[key];
      // erase the original pair
      dll.erase(it);
      // insert the new updated one
      dll.push_front({key, value});
      // update the position in the map
      mp[key] = dll.begin();
    }

    // check if it exceeds the capacity and needs to drop the least used pair
    if (mp.size() > s) {
      // get the least used pair
      auto [lk, lv] = dll.back();
      // pop it from the dll
      dll.pop_back();
      // delete it from the map
      mp.erase(lk);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
