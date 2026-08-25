class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
    
        int mult=1;
      
            while(find(nums.begin(), nums.end(),k*mult) !=nums.end()){
             mult++;
            }
        return k*mult;
    }
};