class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low=1;
        long long high= 1LL*(*max_element(candies.begin(),candies.end()));
        long long total= accumulate(candies.begin(),candies.end(),0LL);
        if(total<k) return 0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long candy=0;
            for(int i=0; i<candies.size(); i++){
               candy+=(candies[i])/mid;
               if(candy>=k) break;
            }
             if(candy>=k){
                low=mid+1;
             }
             else high=mid-1;
        }
        return high;
    }
};