class Solution {
public:
    int solve(string& text1,int i,string& text2,int j, vector<vector<int>>& dp){
        if(i>=text1.size() || j>=text2.size()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int same=0,not_same=0;
        if(text1[i]==text2[j]){
            same=1+solve(text1,i+1,text2,j+1,dp);
        }
        else{
            int case1=solve(text1,i+1,text2,j,dp);
            int case2=solve(text1,i,text2,j+1,dp);
            not_same=max(case1,case2);
        }
        return dp[i][j]=max(same,not_same);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return solve(text1,0,text2,0,dp);
    }
};