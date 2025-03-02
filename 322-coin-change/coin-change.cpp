class Solution {
public:
    int solve(vector<int>& coins,int i,int n,int amount,vector<vector<int>>& dp){
        //we are counting coins if amount is 0 then req coins is also 0
        if(amount==0)return 0;
        if(i>=n)return 1e9;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int take=1e9;
        if(coins[i]<=amount){
            take=1+solve(coins,i,n,amount-coins[i],dp);
        }
        int not_take=solve(coins,i+1,n,amount,dp);
        return dp[i][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(coins,0,n,amount,dp);
        return ans>=1e9 ? -1 : ans;
    }
};