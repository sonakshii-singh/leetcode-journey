class Solution {
public:
    int findSubArr(vector<int> &nums, int mid){
        int subarr=1;
        long long sum=0;
        for(int i=0; i<nums.size(); i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                subarr++;
                sum=nums[i];
            }
        }
        return subarr;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-mid)/2;
            int sub=findSubArr(nums,mid);
            if(sub>k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};