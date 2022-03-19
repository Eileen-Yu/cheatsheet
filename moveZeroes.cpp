// https://leetcode.com/problems/move-zeroes/submissions/


// 1. O(n^2)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idxRange = nums.size() - 1;
        int j = 1;
        for (int i = 0; i < idxRange; i++ ){
            int j = i + 1;
            if(nums[i] == 0) {
                while(nums[j] == 0 && j < idxRange) {j+=1;}
                std::swap(nums[i], nums[j]);
            }
        }
    }
};


// 2. O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int newPos = 0;
      int size = nums.size();
      for(int i = 0; i < size; i++) {
        if(nums[i] != 0) {
          nums[newPos++] = nums[i];
        }
      }
      while(newPos < size) {
        nums[newPos++] = 0;
      }
    }
};
