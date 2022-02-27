class Solution {
public:
    int jump(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> rslt(len,INT_MAX-1);
        rslt[0] = 0;
        
        for(int i = 0; i < len; i++){
            for(int j = 1; j <= nums[i]; j++){
                if( i+j>= len) return rslt[len - 1];
                if(rslt[i] + 1 < rslt[i+j]){
                    rslt[i+j] = rslt[i] + 1; 
                } 
            }
        }
        return rslt[len-1];
       
    }
};