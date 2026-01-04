class Solution {
public:
    int solve(vector<int>& coins,int i,int amount,vector<vector<int>>& dp){
        if(amount<=0){
            return 0;
        }
        if(i<=0){
            return INT_MAX-1;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int include=INT_MAX-1;
        if(coins[i-1]<=amount)include=1+solve(coins,i,amount-coins[i-1],dp);
        int not_include=solve(coins,i-1,amount,dp);
        return dp[i][amount]=min(include,not_include);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1 , vector<int>(amount+1,-1));
        int ans= solve(coins,n,amount,dp);
        return (ans == INT_MAX-1) ? -1 : ans;
    }
};