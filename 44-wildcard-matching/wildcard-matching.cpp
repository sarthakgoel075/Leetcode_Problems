class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base case initialization
        dp[0][0] = true; // Empty pattern matches empty string

        // Initialize dp[i][0] to false for all i > 0
        for (int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }

        // Initialize dp[0][j] where pattern can be all '*'
        for (int j = 1; j <= m; j++) {
            dp[0][j] = (p[j - 1] == '*' && dp[0][j - 1]);
        }

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        // Return the result for the entire string and pattern
        return dp[n][m];
    }
};
