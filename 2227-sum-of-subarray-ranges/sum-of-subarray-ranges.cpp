class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        vector<vector<int>>arr;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            int minVal=nums[i];
            int maxVal=nums[i];
            for(int j=i;j<nums.size();j++){
               maxVal=max(maxVal,nums[j]);
               minVal=min(minVal,nums[j]);
               sum+=maxVal-minVal;
            }
        }
        return sum;
    }
};