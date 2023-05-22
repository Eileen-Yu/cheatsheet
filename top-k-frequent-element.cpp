// https://leetcode.com/problems/top-k-frequent-elements/

// 1. multimap + vector resize
/ class Solution {
public:
  multimap<int, int> invert(unordered_map<int, int> &mymap) {
    multimap<int, int> multiMap;

    unordered_map<int, int>::iterator it;
    for (it = mymap.begin(); it != mymap.end(); it++) {
      multiMap.insert(make_pair(it->second, it->first));
    }

    return multiMap;
  }

  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
      mp[nums[i]]++;

    multimap<int, int> newMap = invert(mp);

    for (multimap<int, int>::reverse_iterator nt = newMap.rbegin();
         nt != newMap.rend(); nt++)
      ans.push_back(nt->second);

    ans.resize(k);

    return ans;
  }
};

// 2. top k --> priority queue to sort the frequency
// + map transformation
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // key: digit, value: frequency
    map<int, int> mp;
    // fill in the map
    for (int i = 0; i < nums.size(); i++) {
      mp[nums[i]]++;
    }

    // transform it to another map for easier search for the original digits
    // later key: frequency, value: [digit1, digit2]
    map<int, vector<int>> mp2;
    for (auto i : mp) {
      mp2[i.second].push_back(i.first);
    }

    // sort the frequency from big to small
    priority_queue<int> pq;
    for (auto i : mp2) {
      pq.push(i.first);
    }

    vector<int> ans;

    while (k != 0) {
      int tmp = pq.top();
      pq.pop();

      // find the corresponding digit
      for (auto i : mp2[tmp]) {
        ans.push_back(i);
        k--;
      }
    }

    return ans;
  }
};
