class Solution {
public:
    int solve(string word1,int n,string word2,int m,vector<vector<int>>& dp){
        if(n==0)return m;
        if(m==0)return n;
        if(dp[n][m]!=-1)return dp[n][m];

        if(word1[n-1]==word2[m-1]){
            return dp[n][m]=solve(word1,n-1,word2,m-1,dp);
        }
        int insert=1+solve(word1,n,word2,m-1,dp);
        int del=1+solve(word1,n-1,word2,m,dp);
        int replace=1+solve(word1,n-1,word2,m-1,dp);

        return dp[n][m]=min({insert,del,replace});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(word1,n,word2,m,dp);
    }
};