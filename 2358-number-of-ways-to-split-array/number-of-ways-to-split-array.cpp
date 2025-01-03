class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        long long leftSum=0;
        long long rightSum=0;
        long long totalSum=accumulate(nums.begin(),nums.end(),0LL);
        for(int i=0;i<n-1;i++){
           leftSum+=nums[i];
           rightSum=totalSum-leftSum;
           if(leftSum>=rightSum)cnt++;
        }
        return cnt;
    }
};