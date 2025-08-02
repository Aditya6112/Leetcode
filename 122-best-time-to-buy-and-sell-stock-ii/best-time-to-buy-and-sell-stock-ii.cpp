class Solution {
public:
    int solve(vector<int>& prices,int i,int n,bool buy,vector<vector<int>>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+solve(prices,i+1,n,0,dp), solve(prices,i+1,n,1,dp));
        }else{
            profit=max(prices[i]+solve(prices,i+1,n,1,dp),solve(prices,i+1,n,0,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,prices.size(),1,dp);
    }
};