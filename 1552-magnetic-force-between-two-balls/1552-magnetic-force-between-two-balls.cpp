class Solution {
public:
    bool canWePlace(vector<int> &pos, int totalBalls, int dist){
        int balls=1,last=pos[0];
        for(int i=1; i<pos.size(); i++){
            if((pos[i]-last)>=dist){
                balls++;
                last=pos[i];
            }
            if(balls>=totalBalls) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int n=pos.size();
        int low=1;
        int high=pos[n-1] - pos[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canWePlace(pos,m,mid)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};