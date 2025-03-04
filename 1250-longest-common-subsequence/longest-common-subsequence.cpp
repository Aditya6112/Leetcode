class Solution {
public:
    int solve(string& text1, string& text2,int n,int m,vector<vector<int>>& dp){
        if(n==0 || m==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        //if both equal then include the count and small the inputs
        if(text1[n-1]==text2[m-1]){
            return dp[n][m]=1+solve(text1,text2,n-1,m-1,dp);
        }
        //not equal then there are 2 cases:
        //1): take the first with smaller input and second string whole
        //2): take the first string whole or second with smaller input
        //return the max of them
        else{
            return dp[n][m]=max(solve(text1,text2,n-1,m,dp),solve(text1,text2,n,m-1,dp));
        }
    }
    //Tabulation method/Top dowm approach
    int solveTopDown(string& text1, string& text2,int n,int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solve(text1,text2,n,m,dp);

        return solveTopDown(text1,text2,n,m);
    }
};