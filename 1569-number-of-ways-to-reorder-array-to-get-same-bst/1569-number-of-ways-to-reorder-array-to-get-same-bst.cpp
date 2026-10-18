
class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> comb;

    int solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return 1;

        int root = nums[0];
        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long ways = comb[n - 1][left.size()];

        ways = ways * solve(left) % MOD;
        ways = ways * solve(right) % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        comb.assign(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] =
                    (comb[i - 1][j - 1] +
                     (long long)comb[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};
