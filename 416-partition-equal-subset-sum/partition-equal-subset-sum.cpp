class Solution {
public:
    bool subsetSum(vector<int>& nums,int n,int target,vector<vector<int>>& dp){
        if(target==0){
            return true;
        }
        if(n==0 && target!=0){
            return false;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        if(nums[n-1]<=target){
            return dp[n][target]=subsetSum(nums,n-1,target-nums[n-1],dp) || 
            subsetSum(nums,n-1,target,dp);
        }
        return dp[n][target]=subsetSum(nums,n-1,target,dp);
    }
    bool canPartition(vector<int>& nums) {
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        if(total_sum%2!=0){
            return false;
        }
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>((total_sum/2)+1,-1));
        return subsetSum(nums,n,total_sum/2,dp);
    }
};