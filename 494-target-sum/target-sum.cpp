class Solution {
public:
    int solve(vector<int>& nums,int idx,int target,int sum,vector<vector<int>>& dp,int total){
        if(idx>=nums.size()){
            if(sum==target)return 1;
            else return 0;
        }
        if(dp[idx][sum+total]!=-1)return dp[idx][sum+total];
        int plus=solve(nums,idx+1,target,sum+nums[idx],dp,total);
        int minus=solve(nums,idx+1,target,sum-nums[idx],dp,total);
        return dp[idx][sum+total]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int count=0;
        int total=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(nums.size(),vector<int>(2*total+1,-1));
        return solve(nums,0,target,sum,dp,total);
    }
};