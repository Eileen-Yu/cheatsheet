// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
//

class Solution {
public:
  int largestInteger(int num) {
    string nn = to_string(num);

    for (int i = 0; i < nn.size(); i++) {
      for (int j = i + 1; j < nn.size(); j++) {
        if (nn[i] % 2 == nn[j] % 2 && nn[i] < nn[j])
          swap(nn[i], nn[j]);
      }
    }

    return stoi(nn);
  }
};
