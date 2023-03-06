// https://leetcode.com/problems/kth-missing-positive-number/description/
// 1. binary search
// math skills :)
class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    // the number of missing elements before the arr[i] is
    // arr[i] - (i + 1)
    // where i+1 is the original number ought to be in this position
    // pick the low & high
    int low = 0;
    int high = arr.size() - 1;

    // find the position of the missing element,
    // should between arr[i] and arr[i-1]

    // end point: high < low
    while (low <= high) {
      int mid = low + (high - low) / 2;

      // already calculate for mid
      if (arr[mid] - (mid + 1) < k)
        low = mid + 1;
      else
        high = mid - 1;
    }

    // original fomula:
    // k - ( arr[start-1] - (start-1+1) ) + arr[start-1]
    return (low + k);
  }
};

// 2. count
class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    int n = arr.size();

    // number to loop
    int i = 1;
    // idx to loop arr
    int j = 0;
    // the k-th number in the complete
    int count = 0;

    while (count < k) {
      if (j < n) {
        // count ++ means need this number
        if (i < arr[j]) {
          count++;
          i++;
        }
        // skip this number because it's in the arr
        else if (i == arr[j]) {
          j++;
          i++;
        }
      }
      // arr has already been looped over
      else {
        count++;
        i++;
      }
    }

    return i - 1;
  }
};
// 3. extra space to record
class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    vector<int> complete;
    int n = arr.size();

    // idx to loop arr
    int j = 0;
    // fill in the comple
    for (int i = 1; i < 10000; i++) {
      if (j < n) {
        if (i < arr[j])
          complete.push_back(i);
        else if (i == arr[j])
          j++;
      }

      else
        complete.push_back(i);
    }

    return complete[k - 1];
  }
};
