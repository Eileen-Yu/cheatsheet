// https://leetcode.com/problems/snapshot-array/description/
// 1. hash table / map to record
// 2. don't refresh the mp on each snap, but on each set
// as it is when the array can be changed
// 3. also, use lower_bound(upper_bound) to find the first element
// that >= (>) certain value
class SnapshotArray {
public:
  int snapId = 0;
  // record the history on each `set` operation
  // idx: idx, value: [key: snapId, value: element]
  vector<map<int, int>> mp;

  SnapshotArray(int length) {
    mp.resize(length);
    // init all elements to 0
    for (int i = 0; i < length; i++)
      mp[i][0] = 0;
  }

  // only when set, the mp needs to be refreshed
  void set(int index, int val) { mp[index][snapId] = val; }

  int snap() {
    snapId++;
    return snapId - 1;
  }

  int get(int index, int snap_id) {
    // if we don't have snapId record exactly == snap_id
    // we need to find the first snapId that < snap_id as the closest
    // lower() would return the iterator of the first element that >= snap_id,
    // if not found, return last(the one behind the end one)
    if (mp[index].find(snap_id) == mp[index].end()) {
      auto it = mp[index].lower_bound(snap_id);
      // here we already except the snapId == snap_id case,
      // so we can decrease it confidently
      // to get the first one that < snap_id
      it--;
      return it->second;
    }
    // the normal case, we can find snapId == snap_id
    return mp[index][snap_id];
  }
};
