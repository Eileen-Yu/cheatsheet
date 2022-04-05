// https://leetcode.com/problems/first-bad-version/
//

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      long long i = 1, j = n;
      long long mid = 0;
      long long rslt = isBadVersion(1);
      
      while(i <= j) {
        mid = (i+j)/2;
        bool f = isBadVersion(mid);
        if(f == false){
          i = mid + 1;
        }
        else{
          rslt = mid;
          j = mid - 1;
        }
      }
      
      return rslt;
    }
};
