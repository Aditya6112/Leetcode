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
    //Optimal solution with Binary Search
    int solveOptimal(vector<int>& nums,int n){
        if(n==0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{
                //just greater idx than nums[i]
                int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[idx]=nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solveOptimal(nums,nums.size());
    }
};