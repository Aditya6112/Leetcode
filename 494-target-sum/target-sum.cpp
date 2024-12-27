class Solution {
public:
    int solve(vector<int>& nums,int idx,int target,int sum){
        if(idx>=nums.size()){
            if(sum==target)return 1;
            else return 0;
        }
        int plus=solve(nums,idx+1,target,sum+nums[idx]);
        int minus=solve(nums,idx+1,target,sum-nums[idx]);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int count=0;
        // vector<vector<int>>dp(nums.size(),vector<int>());
        return solve(nums,0,target,sum);
    }
};