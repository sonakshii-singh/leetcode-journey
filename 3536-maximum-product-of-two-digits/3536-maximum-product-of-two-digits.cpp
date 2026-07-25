class Solution {
public:
    int maxProduct(int n) {
        long long maxi=INT_MIN;
        long long smaxi=INT_MIN;
        while(n>0){
            long long rem=n%10;
           if(rem>maxi){
            smaxi=maxi;
            maxi=rem;
           }
           else if(rem>smaxi){
            smaxi=rem;
           }
            n/=10;
        }
        return maxi*smaxi;
    }
};