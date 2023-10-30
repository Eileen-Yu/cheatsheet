// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// bit manipulation: count the # of 1's in bit representation

// 1. use map to record the number of 1's of each num
class Solution {
public:
  vector<int> sortByBits(vector<int> &arr) {
    // sort from small to big
    // to ensure the nums are always put in ascending order
    sort(arr.begin(), arr.end());

    // {number of 1's, {num1, num2...}}
    map<int, vector<int>> mp;

    // loop each num
    for (auto i : arr) {
      // count of 1's in the bit representation
      int count = 0;
      // avoid change the original i
      int copy = i;

      // bit manipulation: count the # of 1's in the bit representation
      // loop each position from least significant to most significant
      while (copy) {
        count += copy & 1;
        // check the next position
        copy = copy >> 1;
      }

      // store in the map
      mp[count].push_back(i);
    }

    vector<int> ans;
    // loop the map in ordered way: from small to big frequency
    for (auto i : mp) {
      // append each arr of various number of 1's to the ans
      ans.insert(ans.end(), i.second.begin(), i.second.end());
    }

    return ans;
  }
};

// 2. directly use lambda function to customize the sorting rule
class Solution {
public:
  vector<int> sortByBits(vector<int> &arr) {
    // use the lambda function to customize how to sort the nums in the arr
    sort(arr.begin(), arr.end(), [](const int &a, int &b) {
      // __builtin_popcount() count the # of 1's in the bit representation of a
      // number
      int countA = __builtin_popcount(a);
      int countB = __builtin_popcount(b);

      // if the # of 1's are the same: return the smaller one first
      return countA == countB ? a < b : countA < countB;
    });

    return arr;
  }
};
