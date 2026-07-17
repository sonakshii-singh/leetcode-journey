class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        // cntDiv[d] = numbers divisible by d
        vector<long long> cntDiv(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            for (int j = d; j <= mx; j += d)
                cntDiv[d] += freq[j];
        }

        // exact[d] = pairs having gcd exactly d
        vector<long long> exact(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            long long c = cntDiv[d];
            exact[d] = c * (c - 1) / 2;

            for (int j = 2 * d; j <= mx; j += d)
                exact[d] -= exact[j];
        }

        // prefix[g] = number of pairs with gcd <= g
        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + exact[i];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};