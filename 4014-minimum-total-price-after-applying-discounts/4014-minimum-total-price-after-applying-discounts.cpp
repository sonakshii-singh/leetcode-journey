class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());
        int n=prices.size();
        int m=discounts.size();
        double sum=0;
        int i=n-1, j=m-1;
       while(i>=0 && j>=0){
           sum+=(prices[i]*(100-discounts[j]))/100.0;
           i--,j--;
       }
        while(i>=0){
            sum+=prices[i];
            i--;
        }
        return sum;
    }
};