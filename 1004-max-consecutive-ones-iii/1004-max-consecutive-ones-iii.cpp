class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, maxlen=0, zero=0;
        for(r=0; r<nums.size(); r++){
            if(nums[r]==0) zero++;
            if(zero>k){
                if(nums[l]==0) zero--;
                l++;
            }
            int len= r-l+1;
            maxlen=max(maxlen, len);
        }
        return maxlen;
    }
};