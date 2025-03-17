int static t[2501][2501];
class Solution {
public:
    int solve(vector<int>& nums,int n,int i,int prev){
        if(i>=n)return 0;
        if(t[i][prev+1]!=-1)return t[i][prev+1];
        int include=0;
        if(prev==-1 || nums[i]>nums[prev]){
            include=1+solve(nums,n,i+1,i);
        }
        int exclude=solve(nums,n,i+1,prev);
        return t[i][prev+1]=max(include,exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n=nums.size();
        int prev=-1;
        return solve(nums,n,0,prev);
    }
};