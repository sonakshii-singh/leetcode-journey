class Solution {
public:
     
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int stores=0;
            for(int i=0; i<quantities.size(); i++){
               stores+=(quantities[i]+mid-1)/mid;
               if(stores>n) break;
            }
            if(stores>n) low=mid+1;
            else high=mid-1;

        }
        return low;

    }
};