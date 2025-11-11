class Solution {
public:
    int solve(vector<int>& nums,int i,int n,vector<int>& dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int include=nums[i]+solve(nums,i+2,n,dp);
        int not_include=solve(nums,i+1,n,dp);
        return dp[i]=max(include,not_include);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        //include 1st num in arr
        vector<int>nums1(nums.begin(),nums.end()-1);
        vector<int>nums2(nums.begin()+1,nums.end());
        return max(solve(nums1,0,n-1,dp1),solve(nums2,0,n-1,dp2));
    }
};