class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Total path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // dp[i][j][bal] = can we reach (i,j) with balance = bal?
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        // Starting cell must be '('
        if (grid[0][0] == ')')
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int bal = 0; bal <= m + n; bal++) {

                    if (!dp[i][j][bal])
                        continue;

                    // Move down
                    if (i + 1 < m) {
                        int newBal = bal + (grid[i + 1][j] == '(' ? 1 : -1);

                        if (newBal >= 0)
                            dp[i + 1][j][newBal] = true;
                    }

                    // Move right
                    if (j + 1 < n) {
                        int newBal = bal + (grid[i][j + 1] == '(' ? 1 : -1);

                        if (newBal >= 0)
                            dp[i][j + 1][newBal] = true;
                    }
                }
            }
        }

        // Valid parentheses string must end with balance 0
        return dp[m - 1][n - 1][0];
    }
};