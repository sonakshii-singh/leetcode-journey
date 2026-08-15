class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorr = 0;
        bool nonZero = false;

        for(int x : nums) {
            xorr ^= x;
            if(x != 0)
                nonZero = true;
        }
        if(xorr != 0)
            return nums.size();
        if(nonZero)
            return nums.size() - 1;
        return 0;
    }
};