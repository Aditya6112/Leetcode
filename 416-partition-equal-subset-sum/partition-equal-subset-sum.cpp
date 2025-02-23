class Solution {
public:
    //Recursion + Memoization
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
    //Top Down Approach
    bool subsetSumII(vector<int>& nums,int n,int target){
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<target;j++){
                //when arr is empty means size is 0
                if(i==0){
                    dp[i][j]=false;
                }
                //when sum is 0 possible with empty subset always
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        if(total_sum%2!=0){
            return false;
        }
        int n=nums.size();

        //Recursion + Memoization
        // vector<vector<int>>dp(n+1,vector<int>((total_sum/2)+1,-1));
        // return subsetSum(nums,n,total_sum/2,dp);

        //Top Down Approach
        return subsetSumII(nums,n,total_sum/2);
    }
};