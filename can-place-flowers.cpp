// https://leetcode.com/problems/can-place-flowers/description/
// 1. concise loop
class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int len = flowerbed.size();
    for (int i = 0; i < len; i++) {
      // deal with the first & last item
      if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
          (i == len - 1 || flowerbed[i + 1] == 0)) {
        flowerbed[i] = 1;
        n--;
      }
    }

    if (n > 0)
      return false;
    return true;
  }
};

// 2. plain loop
class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int len = flowerbed.size();

    if (n == 0)
      return true;

    if (len == 1 && flowerbed[0] == 0)
      return true;

    if (n >= len)
      return false;

    // deal with the first item
    if (flowerbed[0] == 0 && flowerbed[1] == 0) {
      flowerbed[0] = 1;
      n--;
    }

    for (int i = 1; i < len - 1; i++) {
      if (n == 0)
        break;

      if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
        n--;
        flowerbed[i] = 1;
      }
    }

    // deal with the last item
    if (flowerbed[len - 1] == 0 && flowerbed[len - 2] == 0) {
      n--;
    }

    if (n > 0)
      return false;

    return true;
  }
};
