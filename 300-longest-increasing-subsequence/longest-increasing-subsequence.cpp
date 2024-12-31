class Solution {
public:
    //Top Down
    int solveMem(vector<int>& nums,int curr,int prev,vector<vector<int>>& dp){
        if(curr==nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        //include
        int include=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            include=1+solveMem(nums,curr+1,curr,dp);
        }
        int exclude=solveMem(nums,curr+1,prev,dp);
        return dp[curr][prev+1]=max(include,exclude);
    }

    //Bottom Up
    int solveTab(vector<int>& nums,int n){
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1 || nums[curr]>nums[prev]){
                    include=1+dp[curr+1][curr+1];
                }
                int exclude=dp[curr+1][prev+1];
                dp[curr][prev+1]=max(include,exclude);
            }
        }
        return dp[0][0];
    }

    //Space Optimized
    int solveTabSpaceOptimized(vector<int>& nums,int n){
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1 || nums[curr]>nums[prev]){
                    include=1+nextRow[curr+1];
                }
                int exclude=nextRow[prev+1];
                currRow[prev+1]=max(include,exclude);
            }
            nextRow=currRow;
        }
        return currRow[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solveTabSpaceOptimized(nums,nums.size());
    }
};