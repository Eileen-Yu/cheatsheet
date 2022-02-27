template<typename T>
void bucketSort(T arr[], int n) { // n为要排序几个数
  int i, j, offset;
  T buckets[offset]; //offset是边界，即要排的最大数字+1
  
  for (i = 0; i < offset; i++) {
    buckets[i] = 0;    // 清零
  }

  // 1.计数,将数组arr中的元素放到桶中
  for (i = 0; i < n; i++) {
      buckets[arr[i]]++;  // 将arr[i]的值对应buckets数组的下标，每有一个就加1
  }

  // 2.排序
  for (i = 0, j = 0 ; i < offset; i++) {
    while(buckets[i] > 0) {      // 说明存有元素,相同的整数，要重复输出
      arr[j] = i;
      buckets[i]--;
      j++;
    }
  }
}
