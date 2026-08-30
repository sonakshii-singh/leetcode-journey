class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();

        int l = min(mini, maxi);
        int r = max(mini, maxi);

        int front = r + 1;
        int back = n - l;
        int both = (l + 1) + (n - r);

        return min({front, back, both});
    }
};