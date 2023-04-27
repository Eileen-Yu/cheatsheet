// https://leetcode.com/problems/smallest-number-in-infinite-set/description/
//
// hash map
class SmallestInfiniteSet {
public:
  // hash map to keep the order
  map<int, int> mp;

  SmallestInfiniteSet() {
    for (int i = 1; i <= 1000; i++) {
      mp[i]++;
    }
  }

  int popSmallest() {
    // get the smallest element
    int val = mp.begin()->first;
    // remove the smallest one (map.erase(iterator))
    mp.erase(mp.begin());
    return val;
  }

  void addBack(int num) {
    // does not matter if one element appear multiple times
    mp[num]++;
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
