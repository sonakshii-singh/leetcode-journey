class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int ans=0;
        for(int i=1; i<n; i++){
            if(colors[0]!=colors[i])
              ans=max(ans, i);
        }
        for(int i=0; i<n-1; i++){
            if(colors[n-1]!=colors[i])
              ans=max(ans, n-i-1);
        }
        return ans;
    }
};