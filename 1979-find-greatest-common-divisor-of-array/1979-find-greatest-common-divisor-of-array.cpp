class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return std::gcd(nums[0],nums[nums.size()-1]);
    }
};