class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            long long ops=0;
            for(auto num:nums){
                ops+=(num-1)/mid;
            }
            if(ops<=maxOperations) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};