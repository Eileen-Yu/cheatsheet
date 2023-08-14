// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
// 1. Quick Select: based on quickSort, only go into half each time(like binary
// search)
lass Solution{public : int partition(int l, int r, vector<int> &nums){
    // get a random index within range [l, r] as pivot
    int p = rand() % (r - l + 1) + l;
// record the actual pivot value
int pivot = nums[p];

// quick sort logic:
swap(nums[r], nums[p]);
// record the potential idx to be swapped
int k = l;

// check one by one within [left, right)
for (int i = l; i < r; i++) {
  if (nums[i] < pivot) {
    swap(nums[i], nums[k]);
    // ensure all the left < pivot
    k++;
  }
}
// put the pivot to its correct position
swap(nums[k], nums[r]);
return k;
}

int findKthLargest(vector<int> &nums, int k) {
  int n = nums.size();
  int l = 0, r = n - 1;

  // Quick Select Algorithm:
  // try to put 1 element to its correct position each time
  // and we can cut half of the possible range each time because
  // all the left < pivot & right > pivot
  while (l <= r) {
    // each time return the idx of the element on its right position
    int idx = partition(l, r, nums);
    // if this idx is the one we need
    if (idx == n - k)
      return nums[idx];

    // if our target is on the right part
    else if (idx < n - k)
      l = idx + 1;
    else
      r = idx - 1;
  }

  return -1;
}
}
;

// 2. direct way: priority_queue, which is based on heap
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> pq;
    for (auto i : nums) {
      pq.push(i);
    }

    int tmp;
    while (k--) {
      tmp = pq.top();
      pq.pop();
    }

    return tmp;
  }
};
