class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i==m-1 && j==n-1)return 1;
        if(i>=m || j>=n || obstacleGrid[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int right,down;
        right=solve(obstacleGrid,i,j+1,m,n,dp);
        down=solve(obstacleGrid,i+1,j,m,n,dp);

        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1){
            return 0;
        }
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(obstacleGrid,0,0,m,n,dp);
    }
};