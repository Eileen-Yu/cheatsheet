// https://leetcode.com/problems/sort-an-array/description/
// 1. Heap sort:
// Time Complexity: O(logn) (worst also)
// space complexity: O(1)
class Solution {
public:
  void maxHeapify(vector<int> &nums, int n, int i) {
    // when to return:
    if (i >= n)
      return;

    // the idx of the left & right child
    int left = 2 * i + 1, right = 2 * i + 2;
    // assume the parent is the latgest one
    int max = i;
    // check if the child is larger than parent
    // and change the max as the largest of these three nodes
    // idx of left must < total number of nodes
    if (left < n && nums[left] > nums[max])
      max = left;
    if (right < n && nums[right] > nums[max])
      max = right;

    // if the assumption is false
    if (max != i) {
      // change the max
      swap(nums[max], nums[i]);
      // recurse to heapify the children
      // max is the idx of left / right child
      maxHeapify(nums, n, max);
    }
  }

  void heapSort(vector<int> &nums, int n) {
    // need to heapify every parent to build the heap
    for (int i = n / 2 - 1; i >= 0; i--) {
      maxHeapify(nums, n, i);
    }

    // swap the max and the last element
    // and cut the last one
    // this i is the number of swaps
    for (int i = n - 1; i >= 0; i--) {
      // i is the idx of the last element
      swap(nums[0], nums[i]);
      // from top to down
      maxHeapify(nums, i, 0);
    }
  }

  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    heapSort(nums, n);
    return nums;
  }
};

// 2. merge sort
// Time Complexity: O(nlogn)
// space complexity: O(n)
class Solution {
public:
  void merge(int low, int mid, int high, vector<int> &nums) {
    // when to return
    if (low >= high)
      return;

    int l = low, r = mid + 1, k = 0, size = high - low + 1;
    // init tmp array to store the current merge result
    vector<int> tmp(size, 0);

    while (l <= mid && r <= high)
      tmp[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];

    // if the right one is empty
    while (l <= mid)
      tmp[k++] = nums[l++];

    // if the left one is empty
    while (r <= high)
      tmp[k++] = nums[r++];

    // overwrite the original nums with this sorted piece
    for (k = 0; k < size; k++) {
      nums[k + low] = tmp[k];
    }
  }

  void mergeSort(vector<int> &nums, int start, int end) {
    // when to return
    if (start >= end)
      return;

    int mid = start + (end - start) / 2;
    // recursion
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(start, mid, end, nums);
  }

  vector<int> sortArray(vector<int> &nums) {
    int start = 0, end = nums.size() - 1;
    mergeSort(nums, start, end);
    return nums;
  }
};

// 3. 2-way quick sort
// average Time Complexity: O(nlogn)
// worst case: O(n^2) (when the array is descending, the tree is not balanced)
// so it would TLE
// space complexity: O(n)
// (because the recursion need the stack support)
// namely how many layers of the recursion
// best: O(logn)
// worst O(n)
class Solution {
public:
  int partition(vector<int> &nums, int l, int r) {
    // pick the pivot
    int pivot = nums[l];
    // record its position
    int first = l;

    while (l < r) {
      // first start from right
      // until nums[j] < pivot
      while (l < r && nums[r] >= pivot)
        r--;
      // until nums[i] > pivot
      while (l < r && nums[l] <= pivot)
        l++;

      if (l < r) {
        swap(nums[l], nums[r]);
      }
    }

    swap(nums[first], nums[l]);
    return l;
  }

  void quickSort(vector<int> &nums, int l, int r) {
    // when to return as this is a recursion
    // this means only one element remains
    if (l >= r)
      return;

    int p = partition(nums, l, r);
    quickSort(nums, l, p - 1);
    quickSort(nums, p + 1, r);
  }

  vector<int> sortArray(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    quickSort(nums, l, r);
    return nums;
  }
};
