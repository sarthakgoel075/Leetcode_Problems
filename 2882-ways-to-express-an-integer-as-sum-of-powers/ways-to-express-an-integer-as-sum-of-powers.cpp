class Solution {
public:
    const int mod = 1000000007;

    long long powe(int ind, int x) {
        long long ans = 1;
        for (int i = 0; i < x; i++) {
            ans *= ind;
        }
        return ans;
    }

    int fun(int ind, int n, int x, vector<vector<int>>& dp) {
        if (n == 0) return 1;
        if (n < 0) return 0;

        long long p = powe(ind, x);
        if (p > n) return 0;

        if (dp[ind][n] != -1) return dp[ind][n];

        int take = fun(ind + 1, n - p, x, dp) % mod;
        int nottake = fun(ind + 1, n, x, dp) % mod;

        return dp[ind][n] = (take + nottake) % mod;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return fun(1, n, x, dp);
    }
};
