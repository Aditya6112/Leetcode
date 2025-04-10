class Solution {
public:
    int solve(vector<int>& coins, int n, int amount, vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;
        if (n <= 0)
            return INT_MAX - 1;
        if (dp[n][amount] != -1)
            return dp[n][amount];
        int take = INT_MAX - 1;
        if (coins[n - 1] <= amount) {
            take = 1 + solve(coins, n, amount - coins[n - 1], dp);
        }
        int not_take = solve(coins, n - 1, amount, dp);
        return dp[n][amount] = min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = solve(coins, n, amount, dp);
        return (ans == INT_MAX - 1) ? -1 : ans;
    }
};
