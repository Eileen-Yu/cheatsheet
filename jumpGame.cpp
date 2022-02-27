class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<bool> rslt(len,false);
        rslt[0] = true;
        
        for(int i = 0; i < len; i++) {            
            if(rslt[i] == false) return false;
            for(int j = 1; j <= nums[i]; j++) {
                int pos = i + j;
                if (pos >= len-1) {return true;}
                rslt[pos] = true;
            }
        }
       return rslt[len-1];
        
    }
};