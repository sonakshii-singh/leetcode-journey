class Solution {
public:
    int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );

        // Empty t can be formed in exactly 1 way
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Do not use s[i-1]
                dp[i][j] = dp[i - 1][j];

                // Use s[i-1] if it matches t[j-1]
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] =
                        (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
            }
        }

        return dp[n][m];
    }
};